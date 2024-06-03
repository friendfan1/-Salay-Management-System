package com.restaurantManage.restaurantManage.Controller;

import com.restaurantManage.restaurantManage.DAO.Dish;
import com.restaurantManage.restaurantManage.DAO.DishOrder;
import com.restaurantManage.restaurantManage.dto.DishOrderDTO;
import com.restaurantManage.restaurantManage.service.DishService;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;

import java.io.UnsupportedEncodingException;
import java.net.URLEncoder;
import java.nio.charset.StandardCharsets;
import java.util.List;

@Controller
public class DishController {

    private final DishService dishService;

    public DishController(DishService dishService){
        this.dishService = dishService;
    }

//    @GetMapping("/menu")
//    public String menu(Model model) {
//        System.out.print("成功访问链接\n");
//        List<Dish> dishes = dishService.GetAllDishes();
//        model.addAttribute("dishes", dishes);
//        return "menu";
//    }


    @GetMapping("/{tableNum}/menu")
    public String menu(@PathVariable String tableNum, Model model) {
        List<Dish> dishes = dishService.GetAllDishes();
        model.addAttribute("dishes", dishes);
        model.addAttribute("tableNum", tableNum);
        return "menu";
    }

    @GetMapping("/{tableNum}/menu/{dish}")
    public String orderDish(@PathVariable String tableNum,@PathVariable String dish){
        dishService.dishOrder(tableNum,dish);
        return "redirect:/{tableNum}/menu/" + encodeValue(dish) +"/success";
    }

    @GetMapping("/{tableNum}/menu/{dish}/success")
    public String orderSuccess(@PathVariable String tableNum, @PathVariable String dish, Model model){
        model.addAttribute("tableNum",tableNum);
        model.addAttribute("dish",dish);
        return "success";
    }

    @GetMapping("{tableNum}/menu/ordered")
    public String orderedDishes(@PathVariable String tableNum, Model model){
        List<DishOrderDTO> dishOrdered = dishService.findAllOrderByTableNum(tableNum);
        model.addAttribute("tableNum",tableNum);
        model.addAttribute("dishOrdered",dishOrdered);
        return "ordered";
    }

    public static String encodeValue(String value) {
        try {
            return URLEncoder.encode(value, StandardCharsets.UTF_8.toString());
        } catch (UnsupportedEncodingException e) {
            throw new RuntimeException(e);
        }
    }
}
