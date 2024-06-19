package com.restaurantManage.restaurantManage.service;

import com.restaurantManage.restaurantManage.DAO.Guest;

public interface GuestService {
    int guestCome(int numberOfGuests, int seatRequirement);

    int getPeopleQuantityBefore(int id);

    //Guest guestComeReturnGuest(int numberOfGuests, int seatRequirement);
    String getTableIdByGuestID(int id);

    float getMoneyByGuestID(int id);

    String getMeasureByGuestID(int id);
}
