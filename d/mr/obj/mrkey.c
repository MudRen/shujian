// mrkey.c ��Կ��
// by leontt 2000/10/18

inherit ITEM;

void create()
{
        set_name("��Կ��", ({"hei yaoshi","mrkey"}));
        set("long",
                "����һ�Ѻ�Կ�ס�\n");
        set("unit", "��");
        set("weight", 10);
        set("value", 10000);
        set("no_give", "�������������뿪�㡣\n");
//        set("no_get", "���������ò�������\n");
        set("no_drop", "�������������뿪�㡣\n");
}
