// /u/dubei/miaojiang
 

inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
���������ϵ����䳡���������ӳ���󶼳�����������䡣���˳���Ӣ��
���ˣ���˳��������ʤ���ˣ������ܵõ�����Ů�ӵİ�Ľ��
LONG
        );

        set("exits", ([
                 "northwest" : __DIR__"jiedao5",
                 
        ]));
        set("objects",([
                __DIR__"npc/mnz" : 2,

        ]));

         
        set("outdoors", "miaojiang");

        setup();

}
