package com.restaurantManage.restaurantManage.dto;

import jakarta.persistence.*;
import lombok.NoArgsConstructor;

import java.time.LocalTime;

@NamedStoredProcedureQuery(
        name = "findAllOrderByTableNum",
        procedureName = "查看已点菜Web",
        parameters = {
                @StoredProcedureParameter(mode = ParameterMode.IN, name = "TableNum", type = String.class),
        },
        resultClasses = {DishOrderDTO.class}
)
/*@SqlResultSetMapping(
        name = "ResultMapping",
        classes = {
                @ConstructorResult(
                        targetClass = DishOrderDTO.class,
                        columns = {
                                @ColumnResult(name = "菜名",type = String.class),
                                @ColumnResult(name = "价格",type = Float.class),
                                @ColumnResult(name = "折扣",type = Float.class),
                                @ColumnResult(name = "时间",type = LocalTime.class),
                                @ColumnResult(name = "状态",type = String.class)
                        }
                )
        }
)*/

@Entity
public class DishOrderDTO {
    @Id
    private String dishname;
    private float price;
    private float discount;
    private LocalTime time;
    private String state;

    public DishOrderDTO() {

    }

    public DishOrderDTO(String dishName, float price, float discount, LocalTime time, String state) {
        this.dishname = dishName;
        this.price = price;
        this.discount = discount;
        this.time = time;
        this.state = state;
    }

    public String getDishName() {
        return dishname;
    }

    public void setDishName(String dishName) {
        this.dishname = dishName;
    }

    public float getPrice() {
        return price;
    }

    public void setPrice(float price) {
        this.price = price;
    }

    public float getDiscount() {
        return discount;
    }

    public void setDiscount(float discount) {
        this.discount = discount;
    }

    public LocalTime getTime() {
        return time;
    }

    public void setTime(LocalTime time) {
        this.time = time;
    }

    public String getState() {
        return state;
    }

    public void setState(String state) {
        this.state = state;
    }
}
