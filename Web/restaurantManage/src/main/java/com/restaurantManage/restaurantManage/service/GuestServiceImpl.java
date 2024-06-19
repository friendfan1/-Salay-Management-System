package com.restaurantManage.restaurantManage.service;

import com.restaurantManage.restaurantManage.DAO.Guest;
import com.restaurantManage.restaurantManage.DAO.GuestDAO;
import org.springframework.stereotype.Service;

@Service
public class GuestServiceImpl implements GuestService{

    private final GuestDAO guestDAO;
    public GuestServiceImpl(GuestDAO guestDAO){
        this.guestDAO = guestDAO;
    }
    @Override
    public int guestCome(int numberOfGuests, int seatRequirement) {
        if(numberOfGuests < 0 || seatRequirement <0){
            throw new IllegalArgumentException("No available table for " + seatRequirement + " guests");
        }
        return guestDAO.guestCome(numberOfGuests,seatRequirement);
    }

    @Override
    public int getPeopleQuantityBefore(int id) {
        return guestDAO.getPeopleQuantityBefore(id);
    }

    @Override
    public String getTableIdByGuestID(int id) {
        return guestDAO.getTableIdByGuestID(id);
    }

    @Override
    public float getMoneyByGuestID(int id) {
        return guestDAO.getMoneyByGuestID(id);
    }

    @Override
    public String getMeasureByGuestID(int id) {
        return guestDAO.getMeasureByGuestID(id);
    }


    /*@Override
    public Guest guestComeReturnGuest(int numberOfGuests, int seatRequirement) {
        return null;
    }*/
}
