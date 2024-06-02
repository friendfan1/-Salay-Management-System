package com.restaurantManage.restaurantManage.DAO;

import jakarta.persistence.Column;
import jakarta.persistence.Embeddable;
import jakarta.persistence.Temporal;
import jakarta.persistence.TemporalType;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDate;

@Data
@Embeddable
public class DishOrderId implements Serializable {
    @Column(name = "来客_日期")
    @Temporal(TemporalType.DATE)
    private LocalDate guestComeDate;

    @Column(name = "客户点菜编号")
    private int number;
}
