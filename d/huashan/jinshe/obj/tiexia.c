// Room: /d/huashan/jinshe/obj/tiexia.c
// Date: Look 99/03/25

inherit ITEM;

void create()
{
        set_name("С��ϻ", ({ "tie xia", "xia" }) );
        set_weight(3000);
        set_max_encumbrance(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���������ϻ�ӣ�����մ���������������������ʮ�־�Զ��\n");
                set("value", 1000);
                set("material", "steel");
                set("no_drop", "�������������뿪�㡣\n");
                set("no_get", "�������������뿪�Ƕ���\n");
                set("no_get",1);             
                set("no_drop",1);
                set("amount",30);
                set("jinshe",1);
                }
        setup();
}

int is_container() { return 1; }

void init()
{
        add_action("do_open", "kai");
}

int do_open(string arg)
{
        object me = this_player();
        object ob1;
        object ob;

    if (!arg || (arg != "xia" && arg != "tie xia"))
       {
        return notify_fail("�����ʲô��\n");
        return 1;
       }
    if ((int)query("jinshe") < 1)
        return notify_fail("����˺��ӣ���ϧ�����ǿյġ�\n");       
    else
    {
    if (!present("jinshe miji",me))
       { 
        ob=unew(__DIR__"jinshemiji");
        if(!clonep(ob))
        return notify_fail("���������ϻ����������������һ�\n");
        ob1=new(__DIR__"xinjian");
        write("���Ὺ��ϻ������������һ�������������鼮��һ�ŷ��Ƶ��ż㡣�㼱æ���������ڻ��С�\n");
        ob->move(me);
        ob1->move(me);
        add("jinshe", -1);
        return 1;
       }
        write("�������ϻ����������տյ�ʲôҲû�С�\n");
        add("jinshe", -1);
        return 1;
    }
}

