// ���϶��ƽ��� by hongba
#include <ansi.h>
inherit ITEM;
void setup()
{}
void create()
{
           set_name( YEL"�Ͳ�С��"NOR, ({"youbu xiaobao","youbu","xiaobao"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                
                set("value", 10000000);
               
set("no_cun",1);
set("no_give",1);
set("no_get",1);

                
        }
}

void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{
       object me, obj,ob;
       
       me = this_player();
       obj= this_object();
       
       if( !arg || arg != "xiaobao" ) return notify_fail("��Ҫ��ʲô?\n");
       if ( me->is_busy() || me->is_fighting())
 return notify_fail("����æ���ء�\n");
       
       if( obj->query_temp("owner") != me->query("id"))
              return notify_fail("�����Ū���Ķ�����\n");
       
       message_vision(HIY"$N���Ͳ�����������һ���飬���ַ��ģ�ÿһҳ�϶�д�����������������֣�ûһ��ʶ�á�\n"NOR,me);
       ob = new("clone/misc/shenzujing");
ob->move(me);
       destruct(obj);

       return 1;
}
