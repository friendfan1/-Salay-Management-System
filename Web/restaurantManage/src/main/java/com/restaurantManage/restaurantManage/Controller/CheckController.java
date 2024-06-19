package com.restaurantManage.restaurantManage.Controller;


import com.restaurantManage.restaurantManage.service.GuestService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;

@Controller
public class CheckController {
    @Autowired
    private GuestService guestService;

    /*@GetMapping("/{id}/{tableID}/OK")
    public String checkOk(@PathVariable int id, @PathVariable String tableID,Model model){
        float money = guestService.getMoneyByGuestID(id);
        if(money < 0){
            return "redirect:/" + tableID + "/menu/ordered";
        }
        return "queueing";
    }*/
}
