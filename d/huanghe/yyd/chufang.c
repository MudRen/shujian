// ���� chufang.c
// zly 1999.06.10
 
inherit ROOM; 
 
void create() 
{ 
        set("short", "����");
        set("long", @LONG
�����������ĳ�������һ���ţ�һ�������˱Ƕ�����Ѭ����ֱ����ˮ����
̨���������̣��������������Ĳ��٣���ʦ����æµ�š�
LONG
        );

        set("exits", ([ 
            "east" : __DIR__"dating",
	]));

        set("objects", ([
		FOOD_D("niurou") : 1,
		FOOD_D("liyu") : 1, 
		FOOD_D("sansi") : 1,
		FOOD_D("fan") : 1,
	]));
        setup();
}
