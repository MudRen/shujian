// shangu.c
// ɽ��

inherit ROOM;
void create()
{
	set("short", "ɽ��");
	set("long",@long
��ǰ��Ȼ���ʣ�������һ��Сɽ�ȡ����л��ݴ����������ء�һ��С��
�������۵�ͨ���ľ����֮����
long);
	set("exits",([
	"east" : __DIR__"xiaojing",
]));
	setup();
}