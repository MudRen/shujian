inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
�������鷿����ǽһ�Ŵ���ܣ��ڷ��źܶ���鼮��������ʥ���������
����ų��ԡ�ʥ������������һֱ����Ϊ�٣���������ѧ�����ա�һ������ȥ��
�ƺ��й��ڲ������巽����顣
LONG
	);
	set("exits", ([
		"south" : __DIR__"lang",
		"west"  : __DIR__"shilu1",
	]));
	set("objects",([
              "d/kunlun/obj/string-book" : 1,
	]));
	
	setup();
}
