#include <ansi.h>


inherit SPEC;

void create()
{
set_name (HIY"�齣����"NOR, ({ "baochao"}));
        set("long","����һ��"HIY"�齣�¼�Ԫվ��ͨ�ı���"NOR"������Զһ�(exchange baochao)��������ͨ��������\n");

        set("unit","��");
        set_weight(100);
        set("value",3000000);
//        set("treasure",1); 
        set("degree",1);
        set("flag","spec/baochao");
        set("rest",10);
        set("desc","�齣ͨ��5000ö������Ʊ���ҡ�");
  set("credit",5000);                  
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
            
        if (arg!="zitan baochao" && arg!="baochao")
                return notify_fail("��Ҫ�һ�?\n");
        
        if (!restrict()&& !me->query("buyvip")) {return notify_fail("�������Ѿ�����ʹ��"+this_object()->query("name")+"�ˡ�\n");}
    
        me->add("SJ_Credit", 5000);
 
        write(HIY"��ѱ������Զ�ȡ�����һ�壬ȡ����5000���齣ͨ����\n"NOR);
        degree(); 
        return 1;
}       
