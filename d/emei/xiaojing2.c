// xiaojing2.c
// С�� 

inherit ROOM;
void create()
{
	set("short", "С��");
	set("long",@long
����һ�����ѵ�ɽ��С����һ��ͨ����üɽ��ɽ����һ�߲�֪ͨ�����
��һ·�˼�������ֻ��Щ��֪����С����֨֨ߴߴ���š�
long);
	set("exits",([
	"southwest" : __DIR__"caodi",
	"west" : __DIR__"mu",
	"northdown" : __DIR__"jiudaoguai3",
]));
	setup();
}