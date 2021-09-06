// Write by look
// Modify by bbb
// Modify by snowman@SJ 17/02/2000
// check leitaiuser.
//修改 by hongba
#include <ansi.h>
#include <login.h>
#define SYNTAX  "指令格式：xhw <某人> because <原因> \n"

inherit F_CLEAN_UP;


int main(object me, string str)
{
        object ob, where;
        int times;
        string name, reason;
        mapping note;
        
        if(!str || sscanf(str, "%s because %s", name, reason)!=2 )
                  return notify_fail(SYNTAX);

        if (!objectp(ob = LOGIN_D->find_body(name)))
                  return notify_fail("这个...这个... 有这个人吗?\n");


        if (wiz_level(ob))
                  return notify_fail("对方是共同奋斗的战友噢，你这样做不太好吧？\n");

        if (!objectp(where = environment(ob)))
                  return notify_fail("这个人不知道躲在哪里耶... :-( \n");

        if (file_name(where) == RELAX_ROOM)
                  return notify_fail("他已经在桃花源思过了，不用再抓了。\n");

        if (base_name(ob) == "/cmds/leitai/leitaiuser")
                return notify_fail(ob->name() + "这人是比武擂台Clone出来的，在擂台内让他离开就是了。\n");

        
        tell_object(ob, "您因为［" + reason + "］，暂时被请到小黑屋喝茶。\n"
        );

        message("channel", HIC "\n【纪律】"+ob->query("name")
                +"("+capitalize(ob->query("id"))
                +")因为［" + reason + "］，需要接受调查，决定请到"
                "小黑屋喝茶。\n\n" NOR, users()
        );
        
ob->move("d/wizard/xhw");

        tell_object(me, "你把"+ob->query("name")+"抓到了小黑屋。\n");
        
        
        return 1;
}

string query(string arg)
{
        if(arg=="id") //return now_id;
        return "Wizard";
}


int help(object me)
{
write(@HELP
指令格式 : xhw <某人> because <原因> 
此指令可让你将某个违反规则的玩家移送到小黑屋。
等待处理，查清问题或主动认错后方可放出。
HELP
    );
    return 1;
}

