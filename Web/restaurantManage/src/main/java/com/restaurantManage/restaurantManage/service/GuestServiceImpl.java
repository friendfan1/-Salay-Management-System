package com.restaurantManage.restaurantManage.service;

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
        return guestDAO.guestCome(numberOfGuests,seatRequirement);
    }
}
