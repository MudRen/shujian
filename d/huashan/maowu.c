// Room: /d/huashan/maowu.c
// Date: Look 99/03/25

inherit ROOM;
string look_gang();
void create()
{
	set("short","é��");
	set("long",@long
����һ�����ͨ��é�ݣ�é�ݵ�������һȦ���ǽ��ǽ����һ�����ˮ��
(gang)��ˮ��������һ�������(gaizi)��ˮ�׵��Ա���һ��ľ��,��������һ
����(lock)������Ȼ���˳���ȥ�ˡ����Ժ����һ��ʯ��(desk)������������
��Ĳ�֪�ǿ���Щʲô������
long);
        set("sleep_room", 1);
	set("exits",([
	"southeast" : __DIR__"v-road-1",
]));
	set("item_desc",([
	"gaizi" : "������һ����ľ���Ĵ�ľ�ǣ�������һ�����֡�\n",
	"lock" : "���������˻ҳ�����Ȼ�����кܳ�ʱ�䲻���ˡ�\n",
	"desk" : "����ϸ��ȥ�����澹Ȼ������һ�����ĺ������ߣ���Ȼ��һ��Χ���̡�\n",
	"gang" : (: look_gang :),
]));
	set("outdoors", "��ɽ");
	setup();
}
string look_gang()
{	
	object ob = this_object();
	if( ob->query("xian") == 0 )
	return("����һ����ˮ�ס�\n");
	if( ob->query("xian") == 1 ) {
	if( ob->query("have_water") == 1)
	return("�㿴��ˮ����ʢ������ˮ��\n");
	if( ob->query("have_water") == 0 )
	return("�㿴��ˮͰ�����ˮ�Ѿ����ˡ�\n");
	}
}

void init()
{
	add_action("do_xian", "xian");
	add_action("do_fill","fill");
	add_action("do_close", "close");
	add_action("do_follow", "follow");
}
int do_xian(string arg)
{
	object me = this_player();
	object ob = this_object();
	if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
	return notify_fail("����æ���ģ�\n");

	if(!arg || arg =="" || arg !="gaizi")
	return notify_fail("��Ҫ��ʲô��\n");

	if(ob->query("xian") > 0 ) {
	write("�����Ѿ��Ǵ򿪵��ˡ�\n", me);
	return 1;}

	if(arg == "gaizi") {
	message_vision("$N��ˮͰ�������˿�����\n", me);
	ob->set("xian", 1);
	if( ob->query("have_water") == 1 ) {
	write("�㿴��Ͱ���ˮ�Ѿ��������ˡ�\n" , me);
	return 1; }
	if( ob->query("have_water") == 0 ) {
	write("�㿴��ˮͰ�����ˮ�Ѿ����ˡ�\n", me);
	return 1; }
	}
}

int do_fill(string arg)
{
	object me = this_player();
	object ob = this_object();
	object tong;
	tong = present("shui tong", me);
	if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
	return notify_fail("����æ���ģ�\n");

	if(!arg || arg =="" || arg !="gang")
	return notify_fail("��Ҫ��ʲô��\n");
	
	if(arg =="gang" && present("shui tong", me) ) {
	if( ob->query("xian") < 1) {
	write("�㻹û���ƿ�ˮͰ���أ���ô��СͰ���ˮ������Ͱ�\n", me);
	return 1; }
	if( tong->query("water") < 1) {
	write("СͰ����û��ˮ������ʲô��������\n", me);
	return 1; }
	if( ob->query("have_water") == 1) {
	write("�����ˮ�Ѿ��������ˡ�\n" , me);
	return 1; }
	message_vision("$N��СͰ�����ˮ�����˴�����档\n", me);
	me->set_temp("fill", 1);
	tong->set("long","һ����ľͷ�Ƴɵ�СˮͰ��\n");
	tong->set("weight",180000);
	tong->set("water", 0);
	ob->set("have_water", 1);
	call_out("do_yaba", 2, me);
 	return 1; }                                                              
}

int do_close(string arg)
{
	object me = this_player();
	object ob = this_object();

	if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
	return notify_fail("����æ���ģ�\n");

	if(!arg || arg =="" || arg !="gaizi")
	return notify_fail("��Ҫ��ʲô��\n");

	if( arg == "gaizi") {
	if( ob->query("xian") == 0 ) {
	write("�����Ѿ��ǸǺõ��ˡ�\n", me);
	return 1; }
	else {
	write("�㽫���ӸǺá�\n", me);
	ob->set("xian", 0);
	return 1; }
	}
}
int valid_leave(object me,string dir)
{
	object room;
	room = find_object(__DIR__"maowu");
	remove_call_out("do_yaba");
	if(!(room=find_object(__DIR__"maowu")))
	room=load_object(__DIR__"maowu");
	if(room=find_object(__DIR__"maowu")) {
	call_out("do_clear", 0, room);
	call_out("do_back", 0, me);
	}
        return ::valid_leave(me, dir);
}

int do_follow(string arg)
{
	object me, room;
	me = this_player();
	room = find_object(__DIR__"maowu");
	if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
	return notify_fail("����æ���ģ�\n");

	if(!arg || arg =="" || arg !="yaba")
	return notify_fail("��Ҫ��ʲô��\n");

	if( me->query_temp("fill") == 0) 
	return notify_fail("��Ҫ��ʲô��\n"); 

	if( !present("yaba", environment(me)) )
	return notify_fail("��Ҫ��ʲô��\n"); 

	if(arg == "yaba" ) {
	message_vision("$N�������ư�һ���ж���\n", me);
	message_vision("�ư������ڿն��𣬴���$NԽ��һ��ɽ��С·�ϡ�\n", me);
	call_out("do_back", 0 , me);
	if(!(room=find_object(__DIR__"maowu")))
	room=load_object(__DIR__"maowu");
	if(room=find_object(__DIR__"maowu")) {
	call_out("do_clear", 0, room);
	}
	me->move(__DIR__"place");
	me->delete_temp("fill");
	return 1;
	}
}

void do_back()
{
	if(present("yaba",this_object())) 
	destruct(present("yaba", this_object()));
}
void do_yaba()
{
	object me = this_player();
	object ob = this_object();
	write("���һת��ͻȻ������һ����վ��������������һ������\n", me);
	ob=new(__DIR__"npc/yaba")->move(this_object()); 
}
void do_clear(object room)
{
		room->set("have_water", 0);
}
