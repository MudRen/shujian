// /d/hmy/xiaohuayuan.c

inherit ROOM;

void create()
{
	set("short", "С��԰");
	set("long", @LONG
ͻȻ�ŵ�һ���㣬�ؽ�Ϊ֮һˬ��������������һ�������µ�С��԰�У�
��÷�������ɴ�أ����õü��߽��ģ�����������ԧ������������һ����
�����о������ͷۺ��õ�壬�������ޣ�������ٱ��һ�Ѽ�ɽ֮�н��ż侫
�ŵ�С�ᡣ
LONG
	);
	set("exits", ([ 
	  "up" : __DIR__"dedao",
	  "west" : __DIR__"xiaoshe",
	]));
	set("outdoors", "��ľ��");
	setup();
}
