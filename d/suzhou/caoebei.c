// caoebei.c
// By Jpei

inherit ROOM;

void create()
{
        set("short", "�ܶ�");
        set("long",@long
�ഫ�ܶ��������ڴˣ��������������������Ա�(gravestone)�Լ����¡�
ʱ�������귽ʮ�����Ĳ��ӵ㣬һ�Ӷ��ͣ�����Ĺ�ࡣ
long);
	set("outdoors", "suzhou");

	set("exits",([
		"north" : __DIR__"jiangbian",
		"east" : __DIR__"nongshe",
	]));

	set("item_desc", ([
		"gravestone" : "��������ķ紵���ܣ��������ּ����ɿ������Ǳ����С��ƾ��׸�����촾ʡ���ô�����֡�\n",
		"bei" : "��������ķ紵���ܣ��������ּ����ɿ������Ǳ����С��ƾ��׸�����촾ʡ���ô�����֡�\n",
	]) );

	set("coor/x",40);
  set("coor/y",-250);
   set("coor/z",0);
   setup();
}
