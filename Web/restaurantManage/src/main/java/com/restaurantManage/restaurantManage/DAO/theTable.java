package com.restaurantManage.restaurantManage.DAO;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.Table;

@Entity
@Table(name = "餐桌")
public class theTable {
    @Id
    @Column(name = "桌号")
    private String tableId;

    @Column(name = "容量")
    private int capacity;

    @Column(name = "状态")
    private String state;

    public String getTableId() {
        return tableId;
    }

    public void setTableId(String tableId) {
        this.tableId = tableId;
    }

    public int getCapacity() {
        return capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public String getState() {
        return state;
    }

    public void setState(String state) {
        this.state = state;
    }

    @Override
    public String toString() {
        return "theTable{" +
                "tableId='" + tableId + '\'' +
                ", capacity=" + capacity +
                ", state='" + state + '\'' +
                '}';
    }
}

