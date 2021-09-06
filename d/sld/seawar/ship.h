// ship.h
// 2/7/2002	by augx@sj

inherit ROOM;
#include "ansi.h"
#define	SEAWAR_D	__DIR__"seaward"

#define FIRE_BUSY	20
#define MAX_STEER	30
#define MAX_GUNNER	15

void doinit();
void change_short();

void create()
{	
	set("mode",1);
	doinit();
	set("outdoors", "����");
	set("no_save", 1);
	set("steer",0);
	set("gunner",0);
	set("fire",0);
	set("no_clean_up",1);
	setup();
}

void init()
{
	add_action("do_steer","steer");
	add_action("do_gunner","gunner");
	add_action("do_stand","stand");
	add_action("do_location","location");
	add_action("do_wind","wind");
	add_action("do_water","water");
	add_action("do_way","way");
	add_action("do_turn","turn");
	add_action("do_watch","watch");
	add_action("do_shot","shot");
	add_action("do_jump","jump");
	add_action("do_flee","flee");
}

int do_steer(string arg)
{
	object me = this_player();
	if(me->is_busy()) return notify_fail("����æ���ء�\n");
	if(me->query_temp("seawar/team")!=query("team"))
		return notify_fail("��Ҫ�ڵд��ϸ�ʲô��\n");
	if( objectp(query("steer")) && userp(query("steer")) && environment(query("steer"))==this_object() )
		return notify_fail("�Ѿ��������ƶ��ˡ�\n");
	if( me->query_temp("seawar/char") ) 
		return notify_fail("���Ѿ��ڹ������ˡ�\n");
	me->set_temp("seawar/char","steer");
	set("steer",me);
	message_vision(CYN"$Nվ����β����ʼ�ƶ档\n"NOR, me);
	return 1;
}

int do_gunner(string arg)
{
	object me = this_player();
	if(me->is_busy()) return notify_fail("����æ���ء�\n");
	if(query("mode")>1) return notify_fail("����û���ڿ��Կ�����\n");
	if(me->query_temp("seawar/team")!=query("team"))
		return notify_fail("��Ҫ�ڵд��ϸ�ʲô��\n");
	if( objectp(query("gunner")) && userp(query("gunner"))  && environment(query("gunner"))==this_object() )
		return notify_fail("�Ѿ���������׼�ˡ�\n");
	if( me->query_temp("seawar/char") ) 
		return notify_fail("���Ѿ��ڹ������ˡ�\n");
	me->set_temp("seawar/char","gunner");
	set("gunner",me);
	message_vision(CYN"$Nվ����ͷ��׼�����ڡ�\n"NOR, me);
	return 1;
}

int do_stand(string arg)
{
	object me = this_player();
	if(me->query_temp("seawar/team")!=query("team"))
		return notify_fail("��Ҫ�ڵд��ϸ�ʲô��\n");
	if((string)me->query_temp("seawar/char") == "steer")  set("steer",0);
	if((string)me->query_temp("seawar/char") == "gunner") set("gunner",0);
	me->delete_temp("seawar/char");
	message_vision(CYN"$N��ԭ���Ĺ��������������\n"NOR, me);
	me->start_busy(2);
	return 1;
}

int do_location(string arg)
{
	tell_object(this_player(),SEAWAR_D->query_location(query("job"),query("team"))+"\n");
	return 1;
}

int do_wind(string arg)
{
	SEAWAR_D->query_wind(this_player(),query("job"));
	return 1;
}

int do_water(string arg)
{
	object me = this_player();
	if( (string)me->query_temp("seawar/char")=="steer" || (wizardp(me) && me->query("env/test")) )
		SEAWAR_D->query_water(this_player(),query("job"));
	else
		tell_object(this_player(),"���ֲ����ƶ棬ע�������ʲô��\n");
	return 1;
}

int do_turn(string arg)
{
	int way = 33333;
	object me = this_player();

	if(me->is_busy()) return notify_fail("����æ���ء�\n");
	if(me->query_temp("seawar/team")!=query("team"))
		return notify_fail("��Ҫ�ڵд��ϸ�ʲô��\n");	
	if((string)me->query_temp("seawar/char")!="steer" && !(wizardp(me) && me->query("env/test")))
		return notify_fail("�㲢û�����ƶ氡��\n");	
	if(!arg) return notify_fail("��Ҫת����ٶȰ���\n");	
		
	if(arg && arg=="stop") 
		way = 10000;
	else {
		if(sscanf(arg,"%d",way)<1) {
			if(sscanf(arg,"-%d",way)==1) way = -way;
		}
		if( way > 10000 ) return notify_fail("��Ҫת����ٶȣ�\n");
		if( ABS(way)>360 ) way = way % 360;
		if( way < 0 ) way = 360 + way;
	}

	message_vision(CYN"$N��ʼת��...\n"NOR,me);
	me->start_busy(1);
	if(me->query_temp("seawar/dosteer")<MAX_STEER && me->query_skill("sailing",1)<201) {
		me->improve_skill("sailing", random(me->query_int()));
		me->add_temp("seawar/dosteer",1);
	}
	
	call_out("turn_finish",2,me,way);
	return 1;
}

protected void turn_finish(object me,int way)
{
	if(!objectp(me)) return;
	SEAWAR_D->go(me,query("job"),query("team"),way);
	if(way>360) 
		message_vision(sprintf(CYN"$N�Ѵ�ͣ�¡�\n"NOR,way),me);
	else
		message_vision(sprintf(CYN"$Nת��%d����ɡ�\n"NOR,way),me);		
}

int do_way(string arg)
{
	tell_object(this_player(),SEAWAR_D->query_way(query("job"),query("team"))+"\n");
	return 1;
}

int do_watch(string arg)
{
	int way;
	object me = this_player();

	if(me->query_temp("seawar/team")!=query("team"))
		return notify_fail("��Ҫ�ڵд��ϸ�ʲô��\n");		
	if( (time()-me->query_temp("seawar/look"))<1 && !(wizardp(me) && me->query("env/test")) )
		return notify_fail("�㲻�ǲſ�����\n");
	
	if(!arg) return notify_fail("��Ҫ���ĸ�����\n");
	if(sscanf(arg,"%d",way)>=1 && (way==2 || way==4 || way==8 || way==6)) way = way;
	else if(arg=="south" || arg=="s") way = 2;
	else if(arg=="west"  || arg=="w") way = 4;
	else if(arg=="north" || arg=="n") way = 8;
	else if(arg=="east"  || arg=="e") way = 6;
	else return notify_fail("��Ҫ���ĸ�����\n");
	
	SEAWAR_D->look(this_player(),query("job"),query("team"),way);
	me->set_temp("seawar/look",time());
	return 1;
}

int do_shot(string arg)
{
	int angle,elevation;
	object me = this_player();

	if(me->is_busy()) return notify_fail("����æ���ء�\n");	
	if(me->query_temp("seawar/team")!=query("team"))
		return notify_fail("��Ҫ�ڵд��ϸ�ʲô��\n");	
	if(me->query_temp("seawar/char")!="gunner" && !(wizardp(me) && me->query("env/test")))
		return notify_fail("�㲢û��׼�����ڰ���\n");
	if(query("mode")>1)
		return notify_fail("����û���ڿ��Կ�����\n");
		
	if((time()-query("fire"))<FIRE_BUSY)
		return notify_fail("���ڸոշ��������û��׼�����´η����ء�\n");
	if(!arg || sscanf(arg,"%d %d",angle,elevation)<2)
		return notify_fail("��Ҫ��ʲô�Ƕ���ʲô�����ڣ�\n");
	if(elevation>80 || elevation<30)
		return notify_fail("����������ǹ���Σ�գ����ܻ���Լ�����\n");
	
	if( ABS(angle)>360 ) angle = angle % 360;
	if( angle < 0 ) angle = 360 + angle;
	
	message_vision(HIR"$N��ʼУ׼����װ���ҩ��׼������...\n"NOR,me);
	me->start_busy(2);
	if(me->query_temp("seawar/dogunner")<MAX_GUNNER && me->query_skill("gunnery",1)<201) {
		me->improve_skill("gunnery", random(me->query_int(1)*2));
		me->add_temp("seawar/gunner",1);
	}
	
	set("fire",time());
	call_out("fire_finish",4,me,angle,elevation);
	return 1;
}

protected void fire_finish(object me,int angle,int elevation)
{
	if(!objectp(me)) return;
	SEAWAR_D->fire(me,query("job"),query("team"),angle,elevation);
	message_vision(RED"ֻ�����һ����һö�ڵ����˳�ȥ��\n"NOR,me);
}

int do_jump(string arg)
{
	object me = this_player();
	if( me->is_busy() ) {
		tell_object(this_player(),"����æ���أ�\n");
		return 1;
	}
	if(arg=="ship") {
		if(me->query_temp("seawar/team")!=query("team"))
			tell_object(me,"��Ҫ�ڵд��ϸ�ʲô��\n");
		else
			SEAWAR_D->jump(this_player(),query("job"),query("team"));
	}
	else if(arg=="back") {
		if(me->query_temp("seawar/team")==query("team"))
			tell_object(me,"��Ҫ�������\n");
		else
			SEAWAR_D->back(this_player(),query("job"),query("team"));
	}
	else 
		return 0;
	return 1;
}

int do_flee(string arg)
{
	object me = this_player();
	if(me->is_busy()) return notify_fail("����æ���ء�\n");
	if(me->query_temp("seawar/team")!=query("team"))
		tell_object(me,"��Ҫ�ڵд��ϸ�ʲô��\n");
	else
		SEAWAR_D->flee(me,query("job"),query("team"));
	return 1;
}

void default_mode()
{
	set("steer",0);
	set("gunner",0);
	set("fire",0);
	set("mode",1);
	change_short();
}

void change_mode()
{
	set("mode",2);
	change_short();
}

int query_mode()
{
	return query("mode");
}

void check_kill()
{
	int job,team,i;
	object * inv;
	object ship;

	remove_call_out("check_kill");
	job = query("job");
	team = 3 - query("team");
	if( (SEAWAR_D->dokill(job,team,1) + SEAWAR_D->dokill(job,team,2)) > 0 )
		call_out("check_kill",20);
	else {
		inv = all_inventory(this_object());
		if( !arrayp(inv) || sizeof(inv)<1 ) return;
		for(i=0;i<sizeof(inv);i++) {
			if( inv[i]->query("victim_user") == 1 ) {
				ship = load_object(__DIR__+sprintf("ship%d%d",query("job")+1,3-query("team")));
				if(!ship) continue;
				tell_room(this_object(),"�Ա߹��������󺺣��������ֵİ�ʬ���ӵ����洬��ȥ��\n");
				inv[i]->move(ship);
				tell_room(ship,"ͻȻ�Ӷ��洬�϶�����һ�Ŷ���...\n");
			}
		}		
	}
}
                                                              
