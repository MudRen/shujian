// yaomiao.c

#include <ansi.h>

inherit ITEM;

int gf=0;

void create()
{
        set_name(HIG "ҩ��" NOR, ({"yao miao","miao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",
                "����һ����Ҫ������ˮ(jiao)��ҩ�磬");
                set("unit", "��");
                set("no_get",1);
                set("5type","��");
                set("8type","Ǭ");
                set("stime",0);
                set("location",1);
        }
}

void init()
{
        add_action("do_jiao","jiao");
                        
}

int do_jiao(string arg)
{
        object ob;
        object me=this_player();
        
        if(gf==0)
        {
                gf=1;
                call_out("grow", 10); 
        }
        if(!arg || !objectp(ob=present(arg, environment(me))))
                return notify_fail("��Ҫ��ʲô��\n");
        if((uptime()-ob->query("jtime"))>30)
        {
                call_out("destructing", 1, ob); 
                return notify_fail("���Ѿ�һ���û��ˮ��ҩ������ˡ�\n");
        }
        else if((uptime()-ob->query("jtime"))<10)
        {
                return notify_fail("��ս���ˮ�ˣ��Ȼ���ٽ��ɡ�\n");
        }
        ob->set("jtime",uptime());
        message_vision("$N����һưˮ��ҩ���ֳ�����Щ��\n",me);
        return 1;
}

void destructing(object ob)
{
        if(ob)
                destruct(ob);
}

void grow()
{
        int times;
        object obj;
        object ob=this_object();

        times=uptime()-query("stime");
        if(times>=120)
        {
                if(!objectp(obj=new(__DIR__"yaocao")))
                {
                        call_out("grow", 10);
                } 
                else
                {
                        obj->set("5type",query("5type"));
                        obj->set("8type",query("8type"));
                        obj->set("long",obj->query("long")+query("8type")+query("5type")+"�ԡ�\n");
                        obj->move(environment(this_object()));
                        call_out("destructing", 1, ob); 
                }
        }
        else if(times>=60)
        {
                set("name","��Ƶ�ҩ��");
                call_out("grow", 60);   
        }
        else
        {
                set("name","�����ҩ��");
                call_out("grow", 30);   
        }
}

