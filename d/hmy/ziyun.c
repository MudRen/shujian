// /d/hmy/ziyun.c ������

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
�˴��澰����һ��������������ת����������¶���Ʋ���һӳ��������
����ʱ��ɫһƬ�������ڵ����·����±ߵ��Ʋ�ԭ��������ɫ��
LONG
        );
        set("exits", ([ 
	  "east" : __DIR__"taohua",
	  "west" : __DIR__"wulao",
]));
        set("outdoors", "��ľ��");
        setup();
}
 
