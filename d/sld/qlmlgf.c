// qlmlgf.c
// ������������
inherit ROOM;
void create()
{
	set("short","������");
	set("long",@long
�˴��������Ž���ƽʱ����ϰ��ĵط������п�ǽ�и������ܣ�����
���Ų��ٱ������Ա߷��ż���ʯ���������м���һ��÷��׮�����ӵĴ���
������ż���ɳ����
long);
	set("exits",([
		"east" : __DIR__"qlm",
	]));
	set("objects",([
		BINGQI_D("dagger") : 2,
		__DIR__"npc/obj/slb" : 2,
	]));
	setup();
}