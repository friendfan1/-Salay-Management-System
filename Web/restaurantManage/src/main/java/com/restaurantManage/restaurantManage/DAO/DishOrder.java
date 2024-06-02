package com.restaurantManage.restaurantManage.DAO;

import jakarta.persistence.*;
import lombok.Data;

import java.io.Serializable;
import java.sql.Time;

@Entity
@Table(name = "点菜记录")
@Data
public class DishOrder implements Serializable {

    @EmbeddedId
    private DishOrderId id;

    @Column(name = "来客编号")
    private int guestId;

    @Column(name = "菜名")
    private String dishName;

    @Column(name = "桌号")
    private String tableId;

    @Column(name = "时间")
    private Time guestComeTIme;

    @Column(name = "状态")
    private String state;


}
