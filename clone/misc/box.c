// By Spiderii@yt bt��Ʒ
#include <ansi.h>
inherit SPEC;
void create()
{
        set_name(HIW"���ر���"NOR, ({ "box","baohe" }) );
        set_weight(10);
                set("unit", "��");
                set("long", "һ�����ص���ʺ��ӡ�\n�Ǵ�˵���������Ա���䷲��ı�������ܸ����Ǵ������˺Ͷ��˵�ħ��֮�С�\n�ǲ��Ǿ����������ջ��أ��ǾͿ�򿪣�open�����ɡ�����\n");
                set("value", 0);
                set("material", "wood");
                set("no_drop", "�������صĶ�����ô������Ҷ��ء�\n");
                set("no_get", "�������������뿪�Ƕ���\n");
                set_weight(100);
                set("value",3000000);
                set("treasure",1);
                set("degree",1);
                set("flag","spec/baohe");
                set("desc","��˵�򿪺��ӻ��б�����֡�");
                set("credit",150);    

       setup();
}
void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{        
       int i;
       object me = this_player();
       object obj;
       if(arg!="box" && arg!="baohe")
                    return notify_fail("��Ҫ��ʲô?\n");
       if( me->query("combat_exp") > 4000000
       && random(me->query("kar")) > 25 && random(20) > 15 )
                i = 4;          
        else if( me->query("combat_exp") > 3000000 
        && random(me->query("kar")) > 20 && random(20) > 10 )
                i = 3;
        else if(  me->query("combat_exp") > 1000000
        && random(me->query("kar")) > 15 && random(15) > 15 )
                i = 2;
        else if(  random(me->query("kar")) > 10 )
                i = 1;
        else i = 0;
        obj = new("/d/zhiye/obj/othermaterial");
        if(obj && obj->set_level(5))
        {
                obj->move(this_player());
                message_vision(HIW"$N�ӱ����еõ���һ"+obj->query("unit")+obj->name()+"��\n\n"NOR,me); 
        }
                destruct(this_object());
                return 1;
                
}
