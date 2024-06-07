package com.restaurantManage.restaurantManage.DAO;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;

public interface GuestDAO extends JpaRepository<Guest,GuestId> {
    @Query(value = "SELECT 客人到来有返回值(?1, ?2)", nativeQuery = true)
    int guestCome(int numberOfGuests, int seatRequirement);
}
