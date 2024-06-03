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
public class GuestId implements Serializable {

    private static final long serialVersionUID = 1L;

    @Column(name = "日期")
    @Temporal(TemporalType.DATE)
    private LocalDate guestComeDate;

    @Column(name = "编号")
    private int number;
}
