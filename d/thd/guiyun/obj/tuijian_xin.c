// /u/jpei/guiyun/obj/tuijian_xin.c

inherit ITEM;

void create()
{
        set_name("�Ƽ���", ({ "recommend letter", "letter", "xin" }) );
	set("owner", "jpei");
	set("long","����½�˷�д����ҩʦ��һ���š�\n");
        set_weight(2);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        }
        setup();
}

