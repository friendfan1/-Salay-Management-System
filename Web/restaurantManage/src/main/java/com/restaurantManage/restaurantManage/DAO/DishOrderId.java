package com.restaurantManage.restaurantManage.DAO;

import jakarta.persistence.*;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDate;
import java.util.Objects;

@Data
@Embeddable
public class DishOrderId implements Serializable {

    private static final long serialVersionUID = 2L;

    @Column(name = "来客_日期")
    @Temporal(TemporalType.DATE)
    private LocalDate guestComeDate;

    @Column(name = "客户点菜编号")
    private int number;

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        DishOrderId that = (DishOrderId) o;
        return number == that.number && Objects.equals(guestComeDate, that.guestComeDate);
    }

    @Override
    public int hashCode() {
        return Objects.hash(guestComeDate, number);
    }


}
