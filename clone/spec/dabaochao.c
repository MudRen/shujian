#include <ansi.h>


inherit SPEC;

void create()
{
set_name (HBRED+HIY"��������؛��"NOR, ({ "da baohuo","baohuo"}));
        set("long","����һ��"HBRED+HIY"�齣�¼�Ԫվ��ͨ�ı���"NOR"���ȱ���ţ�ƶ��ˣ�����Զһ�(exchange)��������ͨ��������\n");

        set("unit","��");
        set_weight(100);
        set("value",3000000);
  
    //    set("treasure",1);
        set("no_get",1);
        set("degree",1);
        set("flag","spec/baohuo");
        set("rest",10);
        set("desc","����ͨ��Ҽ�fö����ҊƱ������");
  set("credit",10000);                  
        setup();
}

void init()
{
        
        add_action("do_duihuan","exchange");    
}

int do_duihuan(string arg)
{
        object me=this_player();
        
        if (!arg)
                return notify_fail("��Ҫ�һ�ʲô?\n");
            
        if (arg!="da baohuo" && arg!="baohuo")
                return notify_fail("��Ҫ�һ�?\n");
        
        if (!restrict()&& !me->query("buyvip")) {return notify_fail("�������Ѿ�����ʹ��"+this_object()->query("name")+"�ˡ�\n");}
    
        me->add("SJ_Credit", 10000);
if(!random(4)) CHANNEL_D->do_channel(this_object(), "rumor", HIC"���˿���" + me->name(1) + "ţ��������һ��"HIY"��̴�󱦻�"HIC"��\n"NOR);


        write(HIY"��ţ�ƺ���˦��һ���齣�󱦻���10000���齣ͨ��װ�˸���ӯ������������ƴ����֣�\n"NOR);
        degree(); 
        return 1;
}       
