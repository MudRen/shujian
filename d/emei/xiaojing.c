// xiaojing.c
// ɽ��С��

inherit ROOM;
void create()
{
	set("short","ɽ��С��");
	set("long",@long
����ɽ���е�С����ͨ���ľ����֮�����������Ÿ��ֻ�����ľ������ݣ�
ľ�ȣ�ľ������ɯ须���ޥ����ľܽ�ء�����ɢ�������ĵ�������
long);
	set("exits",([
	"west" : __DIR__"shangu",
	"northeast" : __DIR__"caodi",
]));
	setup();
}