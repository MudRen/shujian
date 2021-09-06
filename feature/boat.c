/* add the following lines in boat file
void init()
{
   add_action("do_turn","turn");
   add_action("do_out","out");
   add_action("do_start","start");
   add_action("lookout","lookout");
   add_action("do_stop","stop");
}
*/

#include <ansi.h>

inherit ITEM;

void dest(object ob);
void over(object ob);
int turnning(object me, string dir);

int lookout()
{
	object me = this_player();
	object ob = this_object();
	string msg;
	int stepe,stepw,steps,stepn;

	stepe=ob->query_temp("stepe");
	stepw=ob->query_temp("stepw");
	steps=ob->query_temp("steps");
	stepn=ob->query_temp("stepn");	

	message_vision("$N��ͷ�쵽���ߣ���Զ����ȥ��\n", me);
	msg = "\n����������һƬ����һ���޼ʣ�";
	if(ob->query("boat_of")){
		msg += "����ͣ�ڰ���û���ء�\n";
		write(msg);
		return 1; 
	}
	if(stepw >10 && steps >10 && steps < 20){
		if(steps < 15) msg += "�������Ϸ�";
		if(steps > 15) msg += "����������";
		if(steps == 15) msg += "��������";
		msg += "��Զ�������Ǹ���ۣ�����Ҳ�в��ٵ��洬����������\n";
	}
	else if(stepe >95 && stepe < 105 && steps >0 && steps < 10){
		if(stepe > 100) msg += "����";
		if(stepe < 100) msg += "�ڶ�";
		if(stepe == 100) msg += "��";
		if(steps < 5) msg += "�Ϸ�";
		if(steps > 5) msg += "����";
		if(steps == 5) msg += "��";
		msg += "��Զ�������п�С����\n";
	}
	else if(stepe >195 && stepe < 205 && stepn >940 && stepn < 960){
		if(stepe > 200) msg += "����";
		if(stepe < 200) msg += "�ڶ�";
		if(stepe == 200) msg += "��";
		if(stepn < 950) msg += "����";
		if(stepn > 950) msg += "�Ϸ�";
		if(stepn == 950) msg += "��";
		msg += "����ߺ������ж�����ȼ�գ�����ӡ������ա�\n";
	}
	else {
		msg += "���ƺ���ʧ�˷���\n";
		if(stepn && stepn > 20){
			if(stepn >= 1100) msg += WHT"���Ѿ�������ǰ���ˣ����ܶ��ǰ�ãã��һ�飬Χ���˸�����\n"NOR;
			else if(stepn >= 800) msg += HIW"����ĵ�ˮҲ�Ѿ��ᶳ������Ư����һ���ĸ�����\n"NOR;
			else if(stepn >= 650) msg += HIB"���󺮷��Х��������ˮ��ҲƯ��һ���С������\n"NOR;
			else if(stepn >= 500) msg += HIM"�����Ѿ���ô̹ǣ����Ҳ�������ء�\n"NOR;
			else msg += "�����ս�ǿ�ң��¶�Ҳ��ʼ�����ˡ�\n";
		}
		else {
			msg += "������������";
			if(stepe) msg += "��ʱ�����Կ�������û�����Ĺ����ں�����߮��\n";
			else if(stepw) msg += "��ʱ�м�ֻ��Ÿ����������������뺣����Զ��\n";
			else msg += "���������񣬿����Ѿ��뿪�����ߺ�Զ�ˡ�\n";
		}
	}    
	write(msg);
	return 1;       
}

void dest(object ob)
{
	destruct(ob);        
}

int do_out()
{
	object me = this_player(), room;

	if(!query("boat_of")) return notify_fail("��Ҫ���������� suicide ���\n");
	if(!(room = find_object(query("boat_of"))))
		room = load_object(query("boat_of"));
	if(room = find_object(query("boat_of"))){
		message_vision("$N�Ӵ���������ȥ��\n\n", me);
		me->move(room);
		message("vision",me->name()+"��"+name()+"������������\n",environment(me), ({me}) );
		return 1;
	}
	write("sea boat error, please call wizard. \n");
	return 1;
}

int do_stop()
{
	object me = this_player();

	if(query("boat_of")) return notify_fail("��û���ں��Ϻ��С�\n");
	message_vision("$N��"+name()+"�ķ��������£�����ͣ���˴��ϡ�\n"NOR, me);
	remove_call_out("turnning");
	return 1;
}

int do_start()
{
	object me, room;

	me = this_player();

	if(!query("boat_of")) return notify_fail("���Ѿ��ں��Ϻ����ˡ�\n");
	if(!(room = find_object(query("boat_of"))))
		room = load_object(query("boat_of"));
	if(room = find_object(query("boat_of"))){
		me->delete_temp("haichuan_paid");
		room->delete("boat_on_sea");
		message_vision("$N��һ��������ඣ���"+name()+"����ʻ��󺣡�\n"NOR, me);
		tell_room(room, HIY+name()+"����ʻ���˴󺣡�\n"NOR);
		delete("boat_of");
		remove_call_out("over");
		call_out("over", 300+random(600)+me->query("combat_exp")/200, this_object());
		return 1;
	}
	write("sea boat error, please call wizard. \n");
	return 1;
}

int do_turn(string arg)
{
	string dir;
	object me, ob;

	me=this_player();
	ob=this_object();

	if (!arg) return notify_fail("��Ҫ���ĸ����򿪴���\n");
	if(query("boat_of")) return notify_fail("����û���ء�\n");
	if (me->is_busy()) return notify_fail("����æ���ء�\n");
	switch(arg) {
		case "��":
		case "east":
		case "e": dir = "��"; break;
		case "��":
		case "west":
		case "w": dir = "��"; break;
		case "��":
		case "north":
		case "n": dir = "��"; break;
		case "��":
		case "south":
		case "s": dir = "��"; break;
		default:
			return notify_fail("��Ҫ���ĸ����򿪣�\n");
	}      
	if(query_temp("dir") == dir) return notify_fail(name()+"������"+dir+"����ʻ���ء�\n");
	write("���"+name()+"��"+dir+"��ʻȥ��\n");
	tell_room(ob, me->name()+"��"+name()+"��"+dir+"��ʻȥ��\n", ({me}));
	if(random(2)==1) me->start_busy(1);
	remove_call_out("turnning");
	turnning(me, dir);
	return 1;
}

int turnning(object me, string dir)
{
	object ob, *obj;
	int stepe,stepw,steps,stepn, i;

	ob=this_object();
	stepe=query_temp("stepe");
	stepw=ob->query_temp("stepw");
	steps=ob->query_temp("steps");
	stepn=ob->query_temp("stepn");

	if(!me || !present(me, ob) || !living(me)) {
		tell_room(ob, ob->name()+"ӭ�����ˣ�����ͣ��������\n");
		return 1;
	}

	switch(dir) {
		case "��":
			if(stepe>=300) over(ob);
			else if(stepw>0 && !stepe) ob->add_temp("stepw", -random(3));
			else if(stepw>0 && stepe>0) {ob->delete_temp("stepw"); ob->add_temp("stepe", random(3));}  
			else ob->add_temp("stepe", random(3)); 
			break;
		case "��":
			if((stepw>=15 && stepn>=300) || (stepw>=100 && stepn>300)){
				write("�����Ǻ������£��㲻������������ʻ�ˡ�\n");
				return 1;
			}
			if(stepe>0 && !stepw) ob->add_temp("stepe", -random(3));  
			else if(stepe>0 && stepw>0) {ob->delete_temp("stepe"); ob->add_temp("stepw", random(3));}  
			else ob->add_temp("stepw", random(3)); 
			break;
		case "��":
			if(stepn>=1400) over(ob);
			if(steps>0 && !stepn) ob->add_temp("steps", -random(3)); 
			else if(steps>0 && stepn>0) {ob->delete_temp("steps"); ob->add_temp("stepn", random(3));}   
			else ob->add_temp("stepn", random(3)); 
			break;
		case "��":
			if(stepw>=15 && stepn<301) {
				write("�ϱ��Ǻ������£��㲻������������ʻ�ˡ�\n");
				return 1;
			}
			if(steps>=400) { over(ob); return 1; }
			if(stepn>0 && !steps) ob->add_temp("stepn", -random(3));    
			else if(stepn>0 && steps>0) {ob->delete_temp("stepn"); ob->add_temp("steps", random(3));}      
			else ob->add_temp("steps", random(3)); 
			break;
		default: break;
	}
	set_temp("dir", dir);
	if(random(10) > 7)
		random(2)?message_vision("$N����"+name()+"����������"+dir+"��ʻȥ��\n",me):
		tell_room(ob, ob->name()+"ӭ�����ˣ���"+dir+"��ʻȥ��\n");

//������������ w15,s15,
	if (steps>=14 && steps<=16 && stepw>=15){
		set("boat_of", "/d/ningbo/xikou");
		load_object(query("boat_of"));
		message_vision("ֻ���˵�һ����"+ob->name()+"�����˰��ߡ�\n\n", me);
		message_vision(HIY+ob->name()+"������������Ϫ�ڿ��˰���������ϰ�(out)�ˡ�\n"NOR, me);
		remove_call_out("close_passage");
		call_out("close_passage", 20, ob);                
		return 0;
	}
//���ߵ��� e100,s5,
	else if (steps>=4 && steps<=6 && stepe>=99 && stepe<=101){
		set("boat_of", "/d/mingjiao/lsd/anbian");
		load_object(query("boat_of"));
		message_vision("ֻ���˵�һ����"+ob->name()+"�����˰��ߡ�\n\n", me);
		message_vision(HIY+ob->name()+"��������һ�������С���Կ��˰���������ϰ�(out)�ˡ�\n"NOR, me);         
		remove_call_out("close_passage");
		call_out("close_passage", 20, ob);              
		return 0;
	}	
//������ e200,n950,
	else if (stepn>947 && stepn<953 && stepe>197 && stepe<203){
		load_object("/d/mingjiao/bhd/dbshan");
		message_vision(HIW"\nͻȻ��ǰ��������һ���޴�ı�ɽ��"+ob->name()+"���Ʋ�ס���ۿ���Ҫ�����ˣ�\n"NOR, me);
		message_vision(HIR"\nֻ���Ե�һ����"+ob->name()+"���ϱ�ɽ�������˶��Ӵ����б�˦�˳�ȥ��\n"NOR, me);
		obj = all_inventory(ob);     
		for(i=0; i<sizeof(obj);i++) {
			if(userp(obj[i])) {                     
				obj[i]->unconcious();
				obj[i]->move("/d/mingjiao/bhd/dbshan");
				obj[i]->apply_condition("cold_wind", 1);
				message("vision", "ֻ���Ե�һ����һ��"+obj[i]->name()+"�Ӵ����ĺ����ﱻ���˳�����\n",environment(obj[i]), ({obj[i]}));
			}
		} 
		dest(ob);                                          
		return 0;
	}
	else if(random(me->query("combat_exp")*2) == me->query("combat_exp") && random(3)==1) over(ob);
	else {
		remove_call_out("turnning");
		call_out("turnning", 1+random(3), me, dir);
	}
	return 1;	
}

void over(object ob)
{
	object *obj, *inv;
	int i,j;
     
	if(!ob) return;
	obj = all_inventory(ob);
	if(obj){                
		message_vision(HIR"\nͻȻһ���紵�����ζ���Φ�ˣ�$NҲ���������죡\n"NOR, ob);
		for(i=0; i<sizeof(obj); i++) {
			inv = all_inventory(obj[i]);
			for(j= 0;j< sizeof(inv);j++){
				if(!inv[j]->query("unique")) continue;
				destruct(inv[j]);
			}
			obj[i]->unconcious();
			obj[i]->move("/d/ningbo/xikou");
			message("vision", "ͻȻһ����ι�����һ��"+obj[i]->name()+"�Ӻ��ﴵ�ϰ�����\n",environment(obj[i]), ({obj[i]}));           
		}
	}   
	dest(ob);
}

void close_passage(object room)
{        
	object *ob;
	int i;

	if(!query("boat_of")) return;
	tell_room(room, "�����������Ȼ���´��ˣ���Ҳ��ȥ�ɡ���\n");
	ob = all_inventory(room);
	for(i = 0; i < sizeof(ob); i++) {
		if(userp(ob[i])) {
			if (!living(ob[i])) tell_room(room, "$N��̧���˴���\n", ob[i]);
			ob[i]->interrupt_me();
			ob[i]->move(room->query("boat_of"));
			if (!living(ob[i])) tell_room(room->query("boat_of"), ob[i]->name() + "��̧���˴���\n", ({ob[i]}));
			else tell_room(room->query("boat_of"), ob[i]->name() + "�����˴���\n", ({ob[i]}));
		}
	}
	dest(this_object());
}
