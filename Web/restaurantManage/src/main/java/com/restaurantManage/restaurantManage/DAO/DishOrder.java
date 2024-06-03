package com.restaurantManage.restaurantManage.DAO;

import jakarta.persistence.*;
import lombok.Data;

import java.io.Serializable;
import java.sql.Time;
import java.time.LocalTime;

@Entity
@Table(name = "点菜记录")
@Data
public class DishOrder{

    @EmbeddedId
    private DishOrderId id;

    @Column(name = "来客编号")
    private int guestId;

    @Column(name = "菜名")
    private String dishName;

    @Column(name = "桌号")
    private String tableId;

    @Column(name = "时间")
    @Temporal(TemporalType.TIME)
    private LocalTime orderTIme;

    @Column(name = "状态")
    private String state;


}
