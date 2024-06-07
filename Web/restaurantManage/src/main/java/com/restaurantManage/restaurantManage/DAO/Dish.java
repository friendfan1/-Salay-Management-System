package com.restaurantManage.restaurantManage.DAO;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.Table;

@Entity
@Table(name="菜品")
public class Dish {
    @Id
    @Column(name = "菜名")
    private String Id;

    @Column(name = "价格")
    private float price;

    @Column(name = "折扣")
    private float discount;

    @Column(name = "材料")
    private String ingredients;

    @Column(name = "类型")
    private String type;

    public String getId() {
        return Id;
    }

    public void setId(String id) {
        Id = id;
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

    public String getIngredients() {
        return ingredients;
    }

    public void setIngredients(String ingredients) {
        this.ingredients = ingredients;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }
}

