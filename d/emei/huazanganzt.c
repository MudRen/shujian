// huazanganzt.c 
// ի��

inherit ROOM;
void create()
{
	set("short","ի��");
	set("long",@long
������Ƕ��һ����ֵ�ի�á�ի��������˳����Ĳ����ͳ��ʣ���λС
ʦ̫������æµ�Ų�����ի�����ϰ��˼��趹��������������Լ���Ѽ����
ζ��ʳ��ի�ú�����һ����ͨ�������ִ���䣬���ߵ�����ͨ��㳡��
long);
	set("exits",([
	    "north" : __DIR__"dcelang",
	    "west" : __DIR__"daxiong",
	    "south" : __DIR__"chuwujian",
]));
	set("objects",([
		"/d/emei/obj/mizhi-tianou" : 1,
		"/d/emei/obj/mala-doufu" : 1,
		"/d/emei/obj/liuli-qiezi" : 1,
        "/d/emei/obj/qingshui-hulu" : 1,
]));
	setup();
}
