inherit ROOM;
void create()
{
	set("short", "����ɽ");
	set("long", @long
����ɽ����ɽ���ƶ׻������������ഫ��������а׻�������Ĺ�ϣ�
��������ɽǰ�����Ĺȣ���ľ��ï����ɫ�������ɽ���ɿ�㣬ʯ����
���������ۻ롣�С�ɽ���������ɫ������Ϊ�����е�һ��ʤ����
long);
set("outdoors", "suzhou");
set("objects",([
__DIR__"obj/xiao-shuzhi" : 1,
__DIR__"obj/da-shugan" : 1,
]));
set("exits",([
"south" : __DIR__"toushanmen",
"northeast" : __DIR__"qsgdao6",
]));
	setup();
}



