package com.restaurantManage.restaurantManage.DAO;

import jakarta.persistence.*;
import lombok.Data;

import java.time.LocalTime;

@Entity
@Data
@Table(name = "来客")
public class Guest {
    @EmbeddedId
    private GuestId id;

    @Column(name = "人数")
    private byte numberOfGuests;

    @Column(name = "座位数要求")
    private byte seatRequirement;

    @Column(name = "排队时间")
    @Temporal(TemporalType.TIME)
    private LocalTime queueTime;

    @Column(name = "入座时间")
    @Temporal(TemporalType.TIME)
    private LocalTime seatingTime;

    @Column(name = "桌号")
    private String tableNumber;

}
