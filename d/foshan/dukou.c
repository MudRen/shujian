
inherit ROOM;
void create()
{
        set("short", "�϶ɿ�");
        set("long", @LONG
��ӭ�����󺣷������˶ɿڣ�������һ���Ѿ��������˺ܾõĶɿڡ�
    ����ɿ��������ٹ�һ�κܳ���ʱ�䣬��Ϊ��ʱ�ʵ�Ϊ�˵õ�������
�Ͼʹ����������˵�е��������С�
LONG);
	set("outdoors", "��ɽ");
	set("no_fight",1);
	set("exits",([
		"north" : __DIR__"shulin_dzd",
		"southwest" : "d/xiakedao/xkroad3",			
"east" : "/d/foshan/haibin",   
	]));	
	setup();
}

#define XKD_D "/d/foshan/xkdd.c"

void init()
{
	object me;
	mapping job;
//    add_action("do_go", "qu");
	me= this_player();
	if(mapp(job = me->query_temp("job_xkd"))){
		if(job["asked"]==1 && !job["ready"] && XKD_D->is_player(me) )			
			call_out("move_to_boat",random(3)+1,me);		
	}
}

void move_to_boat(object me)
{
	mapping job;
	
	if(!XKD_D->is_player(me)) return;	
	if(!mapp(job = me->query_temp("job_xkd"))) return;	
	if(job["asked"]!=1 || job["ready"]==1 ) return;	
	//tell_object(me,file_name(environment(me))+"      "+__FILE__+"\n" );
	if(file_name(environment(me))+".c"!=__FILE__) return;
	if(environment(me)!=this_object()) return;
	job["ready"]=1;
	map_delete(job,"asked");
	XKD_D->player_ready(me);
	tell_object(me,"ֻ��ԶԶ�и���������˸��к����㶨��һ�������������������������ӡ�\n");
	tell_object(me,"��������������Ц���������㲻�������أ�����ϴ��ɡ�\n");
	message_vision("$N��һ����������Ծ���˸�ǳ�ڱ��ϵ�С����\n",me);
	me->move(XKD_D->query_boat());
	tell_room(environment(me),me->name()+"��������������\n",({me}));	
}
