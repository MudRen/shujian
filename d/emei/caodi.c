// caodi.c
// �ݵ�

inherit ROOM;
void create()
{
	set("short", "�ݵ�");
	set("long",@long
��ǰ����һƬ�ݵأ��ݵ��Ͽ��Ÿ�ɫС����΢�紵����ƵƵ��ͷ��һ��ɽ
����ʯ�����£���������Ϲ���������̵ĹϹ����ݵؾ�ͷ��һ��Ĺ�������
���м�Сé�ݡ�
long);
	set("exits",([
	"northeast" : __DIR__"xiaojing2",
	"southwest" : __DIR__"xiaojing",
	"east" : __DIR__"xiaowu",
	"north" : __DIR__"mu",
]));
	setup();
}