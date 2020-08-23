/*********************************************
* this script creates a restaraunt databases *
*********************************************/

-- Drop my restaraunt database
DROP TABLE IF EXISTS bridge_business_menu;
DROP TABLE IF EXISTS bridge_business_owner;
DROP TABLE IF EXISTS bridge_business_cuisine;
DROP TABLE IF EXISTS bridge_usiness_ratings;
DROP TABLE IF EXISTS bridge_business_features;
DROP TABLE IF EXISTS time_of_day_variations;
DROP TABLE IF EXISTS bridge_menu_dishes;
DROP TABLE IF EXISTS ratings;
DROP TABLE IF EXISTS owner;
DROP TABLE IF EXISTS cuisine;
DROP TABLE IF EXISTS features;
DROP TABLE IF EXISTS business;
DROP TABLE IF EXISTS dishes;
DROP TABLE IF EXISTS menu;


-- Creating tables for the database

CREATE TABLE menu (
  menu_id           INT             PRIMARY KEY     AUTO_INCREMENT,
  menu_name         SET('All Day', 'Kids', 'Breakfast', 'Brunch', 'Lunch', 'Dinner', 'Desert', 'Drinks', 'Other')    DEFAULT NULL,
  menu_start        TIME            DEFAULT NULL,
  menu_end          TIME            DEFAULT NULL
);

CREATE TABLE dishes (
  dish_id           INT             PRIMARY KEY     AUTO_INCREMENT,
  dish_name         VARCHAR(50)     NOT NULL,
  price             DECIMAL(5,2)    NOT NULL,
  calories          INT             NOT NULL,
  spice             VARCHAR(50)     DEFAULT NULL,
  other             VARCHAR(255)    DEFAULT NULL
);

CREATE TABLE bridge_menu_dishes (
  menu_id           INT             NOT NULL,
  dish_id           INT             NOT NULL,
  CONSTRAINT bridge_menu_dishes_pk
    PRIMARY KEY (menu_id, dish_id),
  CONSTRAINT bridge_menu_dishes_fk_menu
    FOREIGN KEY (menu_id)
    REFERENCES menu (menu_id),
  CONSTRAINT bridge_menu_dishes_fk_dish
    FOREIGN KEY (dish_id)
    REFERENCES dishes (dish_id)
);

CREATE TABLE business (
  business_id       INT             PRIMARY KEY     AUTO_INCREMENT,
  business_name     VARCHAR(255)    NOT NULL,
  business_phone    VARCHAR(20)     DEFAULT NULL,
  business_email    VARCHAR(255)    DEFAULT NULL,
  delivery_range    INT             DEFAULT NULL,
  specialty         INT             DEFAULT NULL,
  restaurant_type   SET('Family', 'Fast Food', 'Fine Dining', 'Themed', 'Food Truck')    NOT NULL,
  address           VARCHAR(50)     NOT NULL,
  city              VARCHAR(50)     NOT NULL,
  state             VARCHAR(2)      NOT NULL,
  zip               VARCHAR(20)     NOT NULL,
  CONSTRAINT business_fk_dishes
    FOREIGN KEY (specialty)
    REFERENCES dishes (dish_id)
);

CREATE TABLE bridge_business_menu (
  business_id       INT             NOT NULL,
  menu_id           INT             NOT NULL,
  CONSTRAINT bridge_business_menu_pk
    PRIMARY KEY (business_id, menu_id),
  CONSTRAINT bridge_business_menu_fk_business
    FOREIGN KEY (business_id)
    REFERENCES business (business_id),
  CONSTRAINT bridge_business_menu_fk_menu
    FOREIGN KEY (menu_id)
    REFERENCES menu (menu_id)
);

CREATE TABLE owner (
  owner_id          INT             PRIMARY KEY     AUTO_INCREMENT,
  owner_first_name  VARCHAR(255)    NOT NULL,
  owner_last_name   VARCHAR(255)    DEFAULT NULL,
  owner_phone       VARCHAR(50)     DEFAULT NULL,
  owner_email       VARCHAR(255)    DEFAULT NULL
);

CREATE TABLE bridge_business_owner (
  business_id       INT             NOT NULL,
  owner_id          INT             NOT NULL,
  CONSTRAINT bridge_business_owner_pk
    PRIMARY KEY (business_id, owner_id),
  CONSTRAINT bridge_business_owner_fk_business
    FOREIGN KEY (business_id)
    REFERENCES business (business_id),
  CONSTRAINT bridge_buisness_owner_fk_owner
    FOREIGN KEY (owner_id)
    REFERENCES owner (owner_id)
);

CREATE TABLE cuisine (
  cuisine_id        INT             PRIMARY KEY     AUTO_INCREMENT,
  cuisine_desc      VARCHAR(255)    NOT NULL
);

CREATE TABLE bridge_business_cuisine (
  business_id       INT             NOT NULL,
  cuisine_id        INT             NOT NULL,
  CONSTRAINT bridge_business_cuisine_pk
    PRIMARY KEY (business_id, cuisine_id),
  CONSTRAINT bridge_business_cuisine_fk_business
    FOREIGN KEY (business_id)
    REFERENCES business(business_id),
  CONSTRAINT bridge_business_cuisine_fk_cuisine
    FOREIGN KEY (cuisine_id)
    REFERENCES cuisine(cuisine_id)
);

CREATE TABLE ratings (
  rating_id         INT             PRIMARY KEY     AUTO_INCREMENT,
  business_id       INT             NOT NULL,
  user_id           INT             NOT NULL,
  star_rating       INT             NOT NULL,
  review            VARCHAR(255)    DEFAULT NULL,
  CONSTRAINT ratings_fk_business
    FOREIGN KEY (business_id)
    REFERENCES business(business_id)
);

CREATE TABLE features (
  feature_id        INT             PRIMARY KEY     AUTO_INCREMENT,
  feature_desc      VARCHAR(255)    NOT NULL
);

CREATE TABLE bridge_business_features (
  business_id       INT             NOT NULL,
  feature_id        INT             NOT NULL,
  CONSTRAINT bridge_business_features_pk
    PRIMARY KEY (business_id, feature_id),
  CONSTRAINT bridge_business_features_fk_business
    FOREIGN KEY (business_id)
    REFERENCES business(business_id),
  CONSTRAINT bridge_business_features_fk_features
    FOREIGN KEY (feature_id)
    REFERENCES features(feature_id)
);

CREATE TABLE time_of_day_variations (
  business_id       INT             NOT NULL,
  time              ENUM('00:00', '01:00', '02:00', '03:00', '04:00', '05:00', '06:00', '07:00', '08:00', '09:00', '10:00', '11:00', '12:00', '13:00', '14:00', '15:00', '16:00', '17:00', '18:00', '19:00', '20:00', '21:00', '22:00', '23:00')        NOT NULL,
  wait_time        INT             DEFAULT NULL,
  noise_level       INT             DEFAULT NULL,
  CONSTRAINT time_of_day_variations_pk
    PRIMARY KEY (business_id, time),
  CONSTRAINT time_of_day_variations_fk_business
    FOREIGN KEY (business_id)
    REFERENCES business(business_id)
);


-- creating views

CREATE OR REPLACE VIEW full_menus AS
  SELECT
    b.business_id,
    business_name,
    m.menu_id,
    menu_name,
    menu_start,
    menu_end,
    d.dish_id,
    dish_name,
    price,
    calories,
    spice,
    other
  FROM
    dishes d JOIN
	bridge_menu_dishes bmd ON d.dish_id = bmd.dish_id JOIN
    menu m ON bmd.menu_id = m.menu_id JOIN
    bridge_business_menu bbm ON bbm.menu_id = m.menu_id JOIN
    business b ON b.business_id = bbm.business_id
  ORDER BY
    business_id, menu_id, dish_id;

CREATE OR REPLACE VIEW features_by_business AS
  SELECT
    b.business_id,
    business_name,
    feature_desc
  FROM
    features f JOIN
    bridge_business_features bbf ON f.feature_id = bbf.feature_id JOIN
    business b ON bbf.business_id = b.business_id
  ORDER BY
    business_id, f.feature_id;

CREATE OR REPLACE VIEW owner_info_and_business_info AS
  SELECT
    o.owner_id,
    CONCAT(owner_last_name, ', ', owner_first_name) AS owner_full_name,
    owner_phone,
    owner_email,
    b.business_id,
    business_name,
    business_phone,
    business_email,
    address,
    city,
    state,
    zip
  FROM
    owner o JOIN
    bridge_business_owner bbo ON o.owner_id = bbo.owner_id JOIN
    business b ON b.business_id = bbo.business_id
  ORDER BY
    owner_id, business_id;

CREATE OR REPLACE VIEW time_of_day_variations_by_business AS
  SELECT
    b.business_id,
    business_name,
    time,
    wait_time,
    noise_level
  FROM
    time_of_day_variations t JOIN
    business b ON t.business_id = b.business_id
  ORDER BY
    business_id, time;

CREATE OR REPLACE VIEW ratings_by_business AS
  SELECT
    b.business_id,
    business_name,
    r.rating_id,
    user_id,
    star_rating,
    review
  FROM
    ratings r JOIN
    business b ON r.business_id = b.business_id
  ORDER BY
    business_id, rating_id;

CREATE OR REPLACE VIEW cuisine_by_business AS
  SELECT
    b.business_id,
    business_name,
    cuisine_desc
  FROM
    cuisine c JOIN
    bridge_business_cuisine bbc ON c.cuisine_id = bbc.cuisine_id JOIN
    business b ON b.business_id = bbc.business_id
  ORDER BY
    business_id, c.cuisine_id;

CREATE OR REPLACE VIEW general_business_info AS
  SELECT
    b.business_id,
    business_name,
    MIN(time) AS business_open,
    MAX(time) AS business_close,
    business_phone,
    delivery_range,
    dish_id,
    dish_name,
    price,
    calories,
    spice,
    other,
    restaurant_type,
    address,
    city,
    state,
    zip
  FROM
    business b LEFT OUTER JOIN
    dishes d ON b.specialty = d.dish_id JOIN
	time_of_day_variations tdv ON b.business_id = tdv.business_id
  GROUP BY
    business_id
  ORDER BY
    business_id;


-- inserting rows into tables
INSERT INTO menu VALUES
(1, 'Lunch', '10:00', '16:30'),
(2, 'Dinner', '16:30', '22:00'),
(3, 'All Day', NULL, NULL),
(4, 'Breakfast', '6:00', '11:00'),
(5, 'Lunch,Dinner', '11:00', '22:00'),
(6, 'All Day', NULL, NULL);

INSERT INTO dishes VALUES
(1, 'Borscht', 6.99, 500, DEFAULT, DEFAULT),
(2, 'Potato Dumplings', 9.99, 750, DEFAULT, DEFAULT),
(3, 'Honey Cake', 9.99, 900, DEFAULT, DEFAULT),
(4, 'Chicken Goulash', 10.99, 850, DEFAULT, DEFAULT),
(5, 'Cheese Pizza', 10.99, 1000, DEFAULT, DEFAULT),
(6, 'Pineapple Pizza', 11.99, 1100, DEFAULT, DEFAULT),
(7, 'Meat Pizza', 12.99, 1250, DEFAULT, DEFAULT),
(8, 'Platanos Fritos', 5.99, 350, DEFAULT, DEFAULT),
(9, 'Huevos Con Chorizo', 6.99, 600, DEFAULT, DEFAULT),
(10, 'Refresco De Ensalada De Frutas', 2.99, 250, DEFAULT, DEFAULT),
(11, 'Pan Con Pollo', 6.99, 650, DEFAULT, DEFAULT),
(12, 'Pupusas De Loroco Y Queso', 6.99, 550, DEFAULT, DEFAULT),
(13, 'Pupusas De Pollo', 7.99, 650, DEFAULT, DEFAULT),
(14, 'Spicy Wings', 4.99, 400, DEFAULT, DEFAULT),
(15, '3 Alarm Wings', 5.99, 425, DEFAULT, DEFAULT),
(16, 'Honey Mango Wings', 4.99, 450, DEFAULT, DEFAULT);

INSERT INTO bridge_menu_dishes VALUES
(1, 1),
(1, 2),
(1, 3),
(2, 1),
(2, 2),
(2, 4),
(3, 5),
(3, 6),
(3, 7),
(4, 8),
(4, 9),
(4, 10),
(5, 11),
(5, 12),
(5, 13),
(6, 14),
(6, 15),
(6, 16);

INSERT INTO business VALUES
(1, 'Lovely Lithuanian', '555-555-5555', 'orange@mail.dummy.com', DEFAULT, 4, 'Fine Dining', '1337 Anywhere St.', 'San Francisco', 'CA', '58612'),
(2, 'Pizza the Puzzle', '123-555-1337', 'yellow@mail.dummy.com', 10, 6, 'Fast Food', '1279 Pineapple St.', 'Berkeley', 'CA', '45923'),
(3, 'Pupuseria Bonita', '302-555-8888', 'red@mail.dummy.com', DEFAULT, 13, 'Family', '789 Bigroad St.', 'San Jose', 'CA', '24567'),
(4, 'Wings Spot', '542-555-4832', 'salmon@mail.dummy.com', 10, DEFAULT, 'Family,Themed', '123 Eats Drv.', 'Somewhere', 'NY', '30249'),
(5, 'Wings Spots', '1-337-555-1337', 'truck@mail.dummy.com', DEFAULT, DEFAULT, 'Food Truck', 'N/A', 'Somewhere', 'NY', 'N/A');

INSERT INTO owner VALUES
(1, 'Steve', 'Smith', '843-555-3429', DEFAULT),
(2, 'Stephan', 'Doe', DEFAULT, DEFAULT),
(3, 'Estefania', 'Orlando', DEFAULT, 'Estefania@steve.com'),
(4, 'Stephanie', 'Steve', '543-555-2349', 'Stephanie@steve.com'),
(5, 'Seven', 'Nine', DEFAULT, '7of9@startrek.com');

INSERT INTO cuisine VALUES
(1, 'Pizza'),
(2, 'Salvadoran'),
(3, 'Dinner'),
(4, 'Lithuanian'),
(5, 'Wings');

INSERT INTO ratings VALUES
(1, 1, 1, 5, 'So much good stuff!'),
(2, 2, 3, 4, 'Would come back again.'),
(3, 5, 5, 5, DEFAULT),
(4, 4, 2, 1, 'Horrible customer service.'),
(5, 2, 4, 3, 'Adequate.'),
(6, 3, 5, 5, DEFAULT);

INSERT INTO features VALUES
(1, 'wifi'),
(2, 'tv'),
(3, 'buffet'),
(4, 'sit down'),
(5, 'take out');

INSERT INTO bridge_business_menu VALUES
(1, 1),
(1, 2),
(2, 3),
(3, 4),
(3, 5),
(4, 6),
(5, 6);

INSERT INTO bridge_business_owner VALUES
(1, 2),
(2, 1),
(2, 5),
(3, 3),
(4, 4),
(5, 4);

INSERT INTO bridge_business_cuisine VALUES
(1, 4),
(2, 1),
(3, 2),
(4, 5),
(5, 5);

INSERT INTO bridge_business_features VALUES
(1, 1),
(1, 4),
(1, 5),
(2, 1),
(2, 2),
(2, 4),
(2, 5),
(3, 1),
(3, 2),
(3, 4),
(3, 5),
(4, 1),
(4, 2),
(4, 3),
(4, 4),
(4, 5),
(5, 5);

INSERT INTO time_of_day_variations VALUES
(1, '10:00', 8, 4),
(1, '11:00', 10, 6),
(1, '12:00', 10, 6),
(1, '13:00', 10, 6),
(1, '14:00', 8, 4),
(1, '15:00', 6, 2),
(1, '16:00', 6, 2),
(1, '17:00', 8, 4),
(1, '18:00', 8, 4),
(1, '19:00', 10, 6),
(1, '20:00', 10, 6),
(1, '21:00', 10, 6),
(1, '22:00', 10, 6),
(2, '09:00', 0, 2),
(2, '10:00', 0, 3),
(2, '11:00', 3, 5),
(2, '12:00', 5, 7),
(2, '13:00', 5, 7),
(2, '14:00', 3, 6),
(2, '15:00', 1, 4),
(2, '16:00', 1, 4),
(2, '17:00', 1, 4),
(2, '18:00', 1, 4),
(2, '19:00', 1, 4),
(2, '20:00', 1, 4),
(2, '21:00', 0, 2),
(2, '22:00', 1, 3),
(3, '06:00', 5, 6),
(3, '07:00', 5, 6),
(3, '08:00', 3, 5),
(3, '09:00', 1, 3),
(3, '10:00', 0, 1),
(3, '11:00', 3, 3),
(3, '12:00', 5, 7),
(3, '13:00', 5, 7),
(3, '14:00', 3, 5),
(3, '15:00', 1, 3),
(3, '16:00', 2, 3),
(3, '17:00', 2, 3),
(3, '18:00', 1, 3),
(3, '19:00', 3, 4),
(3, '20:00', 3, 4),
(3, '21:00', 3, 4),
(3, '22:00', 3, 3),
(4, '06:00', 0, 1),
(4, '07:00', 0, 1),
(4, '08:00', 1, 2),
(4, '09:00', 1, 3),
(4, '10:00', 1, 3),
(4, '11:00', 5, 9),
(4, '12:00', 5, 9),
(4, '13:00', 5, 9),
(4, '14:00', 1, 5),
(4, '15:00', 1, 3),
(4, '16:00', 1, 3),
(4, '17:00', 1, 4),
(4, '18:00', 3, 6),
(4, '19:00', 3, 7),
(4, '20:00', 3, 6),
(4, '21:00', 1, 4),
(4, '22:00', 3, 4),
(5, '06:00', 0, DEFAULT),
(5, '07:00', 0, DEFAULT),
(5, '08:00', 0, DEFAULT),
(5, '09:00', 0, DEFAULT),
(5, '10:00', 1, DEFAULT),
(5, '11:00', 3, DEFAULT),
(5, '12:00', 3, DEFAULT),
(5, '13:00', 3, DEFAULT),
(5, '14:00', 1, DEFAULT),
(5, '15:00', 1, DEFAULT),
(5, '16:00', 1, DEFAULT),
(5, '17:00', 1, DEFAULT),
(5, '18:00', 1, DEFAULT),
(5, '19:00', 1, DEFAULT),
(5, '20:00', 3, DEFAULT),
(5, '21:00', 3, DEFAULT),
(5, '22:00', 3, DEFAULT);




