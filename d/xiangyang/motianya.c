// update by Lklv for new nanyang city 2001.10.11

#include <ansi.h>
inherit ROOM;

void meet();
void create()
{
        set("short", "摩天崖");
        set("long", @LONG
这里是一处十分峻急的山崖，号称“摩天崖”，崖上山风吹动，沁人心脾。
LONG
        );
        set("outdoors", "襄阳郊外");
        set("exits", ([
                "down" :"/d/group/entry/mjshan2",
                 "up" :"/d/xiangyang/mtyd",
        ]));
 
  setup();

}

void init()
{
 remove_call_out("meet");
call_out("meet",1);
}
void meet()
{
 object me , ob , ob1;
me = this_player();
ob =new("/d/xiangyang/npc/zhangsan");
ob1 =new("/d/xiangyang/npc/lisi");
if (me->query_temp("taixuan/ask"))
{
ob->move(environment(me));
ob1->move(environment(me));

tell_object(me, HIC "\n你刚想离开，突然人影一晃，眼前一花， "
"\n两名奇装打扮的怪人已经走近到你身前，"
               "\n二人一高一矮，一胖一瘦，相映成趣。\n" NOR, me);

remove_call_out("meet");
me->delete_temp("taixuan/ask");
me->set_temp("taixuan/ask2",1);
call_out("meet1",3);
}
return ;
}

int meet1(object me)
{
object ob,ob1;
ob=present("zhang san",this_object());
ob1=present("li si",this_object());
me = this_player();

message_vision  (HIC "\n那瘦高个的面具怪人正是赏善使者张三，"
"\n只听张三说道：“尊驾既然来了，就接下这份请帖吧！”"
"\n声音阴阳怪气之极，$N一时分不清是敌是友。\n" NOR, me);
remove_call_out("meet1");
call_out("meet2",2);

return 1;
}

int meet2(object me)
{
object ob,ob1;
ob=present("zhang san",this_object());
ob1=present("li si",this_object());
me = this_player();
message_vision (HIC "\n$N心下大骇：这两人武功恁地高强，悄无声息间"
"\n来到身边都不曾发觉，这时，一道白光一闪"
"\n一物已到眼前，只得勉力用手去接取。"
"\n只听得一声：“腊月初八，恭请尊驾前来侠客岛一聚！”"
"\n“再看时，两人身形早已远在半里开外。\n" NOR, me);
destruct(ob);
destruct(ob1);

remove_call_out("meet2");

me->delete_temp("taixuan/ask2");
call_out("meet3",2);

return 1;

}

int meet3(object me)
{
        object ob;
        int exp, pot, sc;

       
        ob =new("/d/xiangyang/npc/obj/qingtie");
        me = this_player();


        if (me->query("kar") > 20)
        {
                message_vision( HIR "\n$N" HIR "大吃一惊，方想到适才二人所扔之物，"
                               "说时迟慢，其实只在顷刻，你伸手一接\n恰恰接在手中"
"低头一看时，只见是一张请帖，上写：“腊月初八，侠客岛邀”\n" NOR, me);
                
                ob->move(me, 1);
me->set_temp("taixuan/qingtie",1);

 CHANNEL_D->do_channel(this_object(), "rumor", HIW""+me->query("name")+"得到一份侠客岛请帖。");
                
                                           } else
        {
                message_vision( HIR "\n$N" HIR "大吃一惊，方想到适才二人所扔之物，"
                               "说时迟慢，其实只在顷刻，$N伸手一接\n却不料来劲甚是"
"猛烈，$N" HIR "一个拿捏不住，掉在地上竟然失去踪迹。\n" NOR, me);
                                       }
me->delete_temp("taixuan/1");
        return 1;
}





