// seawar daemon
// 1/28/2002	by augx@sj

#include "ansi.h"
#include <job_mul.h>

#define ANSI_CHAR	"["
#define ANSI_LEFT	"D"
#define ANSI_RIGHT	"C"
#define ANSI_UP		"A"
#define ANSI_DOWN	"B"
#define PI		3.1416

#define MAX_JOBS       8       // 2003.1.7 ���ӵ�  8 ��
#define	MAX_SHOTS	25

#define DIFFICULTY	1100	// smaller is harder , 0 is no hard consider
#define SHIP_SPEED	36
#define SHOT_SPEED	250
#define SHOT_TIME	2	// SHOT_TIME = (60*SHOT_SPEED/7500)
#define WIND_SPEED	18
#define WATER_SPEED	18
#define FIRE_BUSY	25

mapping * sea = ({ (["left": 10000, "top":30000, "right": 32000, "bottom":13000]), 
		   (["left": 50000, "top":30000, "right": 72000, "bottom":13000]), 
		   (["left": 80000, "top":30000, "right":102000, "bottom":13000]), 
		   (["left":100000, "top":30000, "right":122000, "bottom":13000]), 
		   (["left":130000, "top":30000, "right":152000, "bottom":13000]), 
		   (["left":150000, "top":30000, "right":172000, "bottom":13000]), 
		   (["left":180000, "top":30000, "right":202000, "bottom":13000]), 
		   (["left":200000, "top":30000, "right":222000, "bottom":13000]), 
		});
		
mapping * shot = ({ ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , 
		    ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , 
		    ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , 
		    ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , 
		    ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , 
		    ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , 
		    ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , 
		    ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , ([ "x":0 ]) , 
		 });		    	
		 	    		    
mapping * tshot = ({ ([ "x":0, "y":0 ]) , 
		     ([ "x":0, "y":0 ]) , 
		     ([ "x":0, "y":0 ]) , 
		     ([ "x":0, "y":0 ]) , 
		     ([ "x":0, "y":0 ]) , 
		     ([ "x":0, "y":0 ]) , 
		     ([ "x":0, "y":0 ]) , 
		     ([ "x":0, "y":0 ]) , 
		  });		    		    	
		  
string startroom1,startroom2;	    
		  
void nature(int flag);
void clear(int idx);

void create()
{
	startroom1 = "/d/tanggu/gangkou";
	startroom2 = "/d/sld/lgxroom";
}

/////////////////////////////////////////////////////////////////
// this two functions show inner mapping data for debug
mapping query_sea(int idx)
{
	idx = MAX(idx,0);
	idx = MIN(idx,MAX_JOBS);
	return sea[idx];
}

mapping query_shot(int idx)
{
	idx = MAX(idx,0);
	idx = MIN(idx,MAX_SHOTS);
	return shot[idx];
}

void move(int idx,int team,int x,int y)
{
	sea[idx][sprintf("x%d",team)] = x;
	sea[idx][sprintf("y%d",team)] = y;
}

/////////////////////////////////////////////////////////////////
// these functions show states
string query_location(int idx,int team)
{
	int x,y;
	x = sea[idx][sprintf("x%d",team)];
	y = sea[idx][sprintf("y%d",team)];
	return CYN"����ϸ�Ĺ۲����̣�����ս���ķ�λ�ǣ��������Զ�"+sprintf("%d.%.3d",x/1000,x%1000)+"��Ա�"+sprintf("%d.%.3d",y/1000,y%1000)+"��"NOR;
}

void query_wind(object me,int idx)
{
	string wind;
	switch( sea[idx]["wind"] ) {
		case 1: wind = "���Ϸ�"; break;
		case 2: wind = "�Ϸ�";   break;
		case 3: wind = "���Ϸ�"; break;
		case 4: wind = "����";   break;
		case 6: wind = "����";   break;
		case 7: wind = "������"; break;
		case 8: wind = "����";   break;
		case 9: wind = "������"; break;
		default: tell_object(me,CYN"����ϸ�۲���ţ���������û�з硣"NOR); return;
	}
	tell_object(me,CYN"����ϸ�۲���ţ��������ڵķ����ǣ�"+wind+"�����ٴﵽ��"+CHINESE_D->chinese_number(sea[idx]["windspeed"])+"����\n"NOR);
}

void query_water(object me,int idx)
{
	string water;
	switch( sea[idx]["water"] ) {
		case 1: water = "����"; break;
		case 2: water = "��";   break;
		case 3: water = "����"; break;
		case 4: water = "��";   break;
		case 6: water = "��";   break;
		case 7: water = "����"; break;
		case 8: water = "��";   break;
		case 9: water = "����"; break;
		default: tell_object(me,CYN"����ϸ�۲�󺣣��������������޲���"NOR); return;
	}
	tell_object(me,CYN"����ϸ�۲�󺣣��������ڵĺ��������ǣ�"+water+"�����ٴﵽ��"+CHINESE_D->chinese_number(sea[idx]["waterspeed"])+"����\n"NOR);
}

string query_way(int idx,int team)
{
	int way = sea[idx][sprintf("way%d",team)];
	if(way>360) 
		return "����ս������ֹͣ״̬��";
	else
		return sprintf("����ս���ĺ����ǣ�%d�ȡ�",way);
}

/////////////////////////////////////////////////////////////////
// these funcstion to change the state
protected void move2ship(object me1,object me2,object ship)
{
	if(objectp(me1)) me1->move(ship);
	if(objectp(me2)) me2->move(ship);
}

protected void rank(object me,int team)
{
	string title;
	int skill = MAX( me->query_skill("saling",1) , me->query_skill("gunnery",1) );
	if(team==1) {
		title = HIY"����ˮʦ";
		if(skill<25) title += "����";
		else if(skill< 50) title += "ǧ��";
		else if(skill< 75) title += "�ر�";
		else if(skill<100) title += "��˾";
		else if(skill<125) title += "�λ�";
		else if(skill<150) title += "�ν�";
		else if(skill<175) title += "����";
		else if(skill<200) title += "�ܱ�";
		else title += "�ᶽ";
		title += NOR;
	}
	else {
		title = HIR"������";
		if(skill<25) title += "����";
		else if(skill< 50) title += "�����Ż���";
		else if(skill< 75) title += "�����Ż���";
		else if(skill<100) title += "�����Ż���";
		else if(skill<125) title += "�����Ż���";
		else if(skill<150) title += "�����Ż���";
		else if(skill<175) title += "��̳����";
		else if(skill<175) title += "��������";
		else title += "�ƽ̻���";
		title += NOR;
	}
	me->set_temp("title",title);
}

string play(object me1,object me2,int team)
{
	object ship1,ship2;
	int i;
	string t,t2;
	
	for(i=0;i<MAX_JOBS;i++)
		if( sea[i]["playing"]==0 ) break;
	if(i>=MAX_JOBS) return "Ŀǰ���ǵ������Ѿ��㹻�ˣ����ǵ�һ��������ɡ�";
	
	t = sprintf("%d",team);
	t2 = sprintf("%d",3-team);
	
	sea[i]["playing"] = 1;
	sea[i]["player"+t+"1"] = me1;
	sea[i]["player"+t+"2"] = me2;
	sea[i]["team"+t] = 1;
	
	sea[i]["player"+t2+"1"] = 0;
	sea[i]["player"+t2+"2"] = 0;
	sea[i]["team"+t2] = 0;

	ship1 = load_object(sprintf(__DIR__"ship%d1",i+1));
	ship2 = load_object(sprintf(__DIR__"ship%d2",i+1));
	if( !ship1 || !ship2 ) return "�����޷��ҵ�ս�����뱨����ʦ��";
	ship1->default_mode();
	ship2->default_mode();
	
	sea[i]["x1"] = sea[i]["left"] + random(sea[i]["right"]-sea[i]["left"]);
	sea[i]["y1"] = sea[i]["bottom"];
	sea[i]["x2"] = sea[i]["left"] + random(sea[i]["right"]-sea[i]["left"]);
	sea[i]["y2"] = sea[i]["top"];
	sea[i]["ship1"] = ship1;
	sea[i]["ship2"] = ship2;
	sea[i]["speed1"] = SHIP_SPEED;
	sea[i]["speed2"] = SHIP_SPEED * 8/10;
	sea[i]["hp1"] = 100;
	sea[i]["hp2"] = 120;
	sea[i]["tx1"] = 0;
	sea[i]["ty1"] = 0;
	sea[i]["tx2"] = 0;
	sea[i]["ty2"] = 0;
	sea[i]["way1"] = 10000;
	sea[i]["way2"] = 10000;
	sea[i]["gain1"] = 0;
	sea[i]["gain2"] = 0;
	sea[i]["angle"] = -1;
	sea[i]["fire"] = 0;
	sea[i]["killer1"] = 3;
	sea[i]["killer2"] = 3;
	sea[i]["starttime"] = time();
	nature(1);
	
	me1->apply_condition("job_busy",60);
	me2->apply_condition("job_busy",60);
	me1->set_temp("seawar/job",i);
	me2->set_temp("seawar/job",i);
	me1->set_temp("seawar/team",team);
	me2->set_temp("seawar/team",team);
	me1->set("startroom", (team==1?startroom1:startroom2) );
	me2->set("startroom", (team==1?startroom1:startroom2) );
	me1->set_temp("seawar/dosteer",0);
	me2->set_temp("seawar/dosteer",0);
	me1->set_temp("seawar/dogunner",0);
	me2->set_temp("seawar/dogunner",0);
	rank(me1,team);
	rank(me2,team);

	log_file("job/seawar",sprintf("��ʼ����,%s%s:%d,%s%s:%d\n",
		me1->name(), "("+me1->query("id")+")", me1->query("combat_exp"),
		me2->name(), "("+me2->query("id")+")", me2->query("combat_exp") ),me1,me2);
	
	remove_call_out("war");
	call_out("war",2);
	
	call_out("move2ship",2,me1,me2,(team==1?ship1:ship2));
	if(team==1)
		return "�ã����ǸϿ��ս�ɣ����Ҫ�����н������Ҵ��������";
	else
		return "�ã����ǸϿ��ս�ɣ����Ҫ�����н������ҽ�������";
}

void flee(object me,int idx,int team)
{
	object me1,me2,startroom;
	int g,exp,e,pot,shen,distance,x,y,utime,limit,ext,db_exp;
	string s,mename,t = sprintf("%d",team);
	
	x = sea[idx]["x1"] - sea[idx]["x2"];
	y = sea[idx]["y1"] - sea[idx]["y2"];
	if( ABS(x)>3000 || ABS(y)>3000 )
		distance = 3001 * 3001;
	else
		distance = x*x + y*y;

	if(team==1) {
		if( (sea[idx]["y1"]-7000)>sea[idx]["bottom"] || distance<(3000*3000) ) {
			tell_object(me,"���ǻ�û������ս���ء�\n");
			return;
		}
		else
			tell_room(sea[idx]["ship1"],"ս����ʻ��ã����㿴��½��...\nս���������������ǻص����ϡ�\n");
		me1 = sea[idx]["player11"];
		me2 = sea[idx]["player12"];
		startroom = load_object(startroom1);
	}
	else {
		if( (sea[idx]["y2"]+7000)<sea[idx]["top"] || distance<(3000*3000) ) {
			tell_object(me,"���ǻ�û������ս���ء�\n");
			return;
		}
		else
			tell_room(sea[idx]["ship2"],"ս����ʻ��ã����㿴��½��...\nս���������������ǻص����ϡ�\n");
		me1 = sea[idx]["player21"];
		me2 = sea[idx]["player22"];
		startroom = load_object(startroom2);
	}
	if(objectp(me1)) me1->move(startroom);
	if(objectp(me2)) me2->move(startroom);
	
	mename = "";
	if(objectp(me1)) mename  = me1->query("name");
	if(objectp(me1) && objectp(me2)) mename += "��";
	if(objectp(me2)) mename += me2->query("name");
	
	g = sea[idx]["gain"+t];
	if(g<20)  g = 0;
	if( g>0 ) {
		if(objectp(me1)) me1->clear_condition("job_busy");
		if(objectp(me2)) me2->clear_condition("job_busy");
                if(objectp(me1)) {me1->add("job_time/�������ս",1);
                                me1->set("job_name","��������ս");}
                if(objectp(me2)){ me2->set("job_name","��������ս");
                             me2->add("job_time/�������ս",1);}
		
		if(team==1) {
			if(g<60) s = "������ô��ôû�ð���";
			else if(g<120) s = "������ǿ������Ҫ�����͡�";
			else if(g<240) s = "��Ȼ�����н�������û�ܼ���о�����ҪŬ������";
			else if(g<340) s = "����о��󲿣�ʵ���������´ζ�Ҫȫ�ߵо���";
			else s = "ȫ�ߵо��������Ҵ�������������ض�������ϣ��úüν���ȣ�";
			tell_room(startroom,CYN"ʩ��˵����"+mename+"������"+s+"\n"NOR);
		}
		else {
			if(g<60) s = "������ô��ôû�ð���";
			else if(g<120) s = "������ǿ������Ҫ�����͡�";
			else if(g<240) s = "��Ȼ�����н�������û�ܼ���о�����ҪŬ������";
			else if(g<340) s = "����о��󲿣�ʵ���������´ζ�Ҫȫ�ߵо���";
			else s = "ȫ�ߵо����������������磬�Ϸ�ض������������úüν���ȣ�";
			tell_room(startroom,CYN"½����˵����"+mename+"������"+s+"\n"NOR);
		}
	}
	else {
		if(team==1)
			tell_room(startroom,CYN"ʩ��˵����"+mename+"�����Ǵ����Ҵ������������̫û���ˣ�\n"NOR);
		else
			tell_room(startroom,CYN"½����˵����"+mename+"�����Ǵ������������磬����̫û���ˣ�\n"NOR);
	}
	
	if(objectp(me1)) me1->delete_temp("seawar");
	if(objectp(me2)) me2->delete_temp("seawar");
	clear(idx);
	
	if(g<=0) {
		if(!objectp(me1)) me1 = me2;
		if(!objectp(me2)) me2 = me1;
		log_file("job/seawar",sprintf("����ʧ��,t:%-4d,%s%s,%s%s\n",
			time()-sea[idx]["starttime"],
			me1->name(), "("+me1->query("id")+")", 
			me2->name(), "("+me2->query("id")+")" ),me1,me2);
		return;
	}

	utime = time() - sea[idx]["starttime"];
        if(utime<600) exp = g * 35*4/10;
        else if(utime<660) exp = g * 36*4/10;
        else if(utime<720) exp = g * 38*4/10;
        else if(utime<780) exp = g * 41*4/10;
        else if(utime<900) exp = g * 45*4/10;
        else if(utime<1020) exp = g * 46*4/10; 
        else if(utime<1200) exp = g * 48*4/10;
        else if(utime<1500) exp = g * 51*4/10;
        else exp = g * 53*3/10;
	
	if(g<240 && g>120) exp -= 200+random(50);
	if(g>240) g+= 200+random(50);
		
	e = exp;
	pot = exp / 5;
        exp = exp*2/3 + random(exp/3);

if(exp>5500)  exp =5500 + random(500);

db_exp = exp /3 + random(exp/2);
	pot = pot*4/5 + random(pot*2/5);
	shen = exp * 3;
	if(team==2) {
		shen = -shen;
		exp += 50;
	}

	if(objectp(me1))
 {
		me1->add("combat_exp", exp );
		me1->add("potential",pot);		
		me1->add("shen",shen);
		if ( (int)me1->query("potential", 1) > (int)me1->query("max_pot", 1) )
			me1->set("potential" , me1->query("max_pot", 1) );
		tell_object(me1, HIC"�㱻������"+CHINESE_D->chinese_number(exp)+"�㾭�飬"+CHINESE_D->chinese_number(pot)+"��Ǳ��");

		if(team==1) tell_object(me1,"����о�����������ʤ��ǰ��\n"NOR);
		else tell_object(me1,"��о�а��֮����ʤ��ǰ��\n"NOR);


   ext = me1->query("relife/exp_ext");
                if( ext >0 ) {    
                  me1->add("combat_exp", exp* ext /20 );
		tell_object(me1, HIC"����ϸ�����Ÿղź�ս�Ĺ��̣��ֶ�������"+CHINESE_D->chinese_number(exp*ext/20)+"�㾭�飡\n"NOR);
    
                                          }


   if( me1->query_condition("db_exp") ) {
          me1->add("combat_exp", db_exp );

          	tell_object(me1,HBGRN"˫�����齱���ڼ䣬������������"+chinese_number(db_exp)+"��ʵս���飡\n"NOR);}
}


	if(objectp(me2)) {

                me2->add("combat_exp", exp );		
		me2->add("potential",pot);
		me2->add("shen",shen);
		if ( (int)me2->query("potential", 1) > (int)me2->query("max_pot", 1) )
			me2->set("potential" , me2->query("max_pot", 1) );
		tell_object(me2, HIC"�㱻������"+CHINESE_D->chinese_number(exp)+"�㾭�飬"+CHINESE_D->chinese_number(pot)+"��Ǳ��");

 


		if(team==1) tell_object(me2,"����о�����������ʤ��ǰ��\n"NOR);
		else tell_object(me2,"��о�а��֮����ʤ��ǰ��\n"NOR);

  ext = me2->query("relife/exp_ext");
                if( ext >0 ) {    
                  me2->add("combat_exp", exp* ext /20 );
		tell_object(me2, HIC"����ϸ�����Ÿղź�ս�Ĺ��̣��ֶ�������"+CHINESE_D->chinese_number(exp*ext/20)+"�㾭�飡\n"NOR);
    
                                          }


   if( me2->query_condition("db_exp") ) {
          me2->add("combat_exp", db_exp );

          	tell_object(me2,HBGRN"˫�����齱���ڼ䣬������������"+chinese_number(db_exp)+"��ʵս���飡\n"NOR);}

}
	if(!objectp(me1)) me1 = me2;
	if(!objectp(me2)) me2 = me1;
	limit = 7000 * utime / 3600;
	log_file("job/seawar",sprintf("�������,t:%-4d,g:%-3d,e:%-4d(%4d;%4d;%4d),p:%-3d,s:%-5d,%s%s,%s%s\n",
		time()-sea[idx]["starttime"],g,exp,e,limit,e-limit,pot,shen,
		me1->name(), "("+me1->query("id")+")",
		me2->name(), "("+me2->query("id")+")" ),me1,me2);
}

int go(object me,int idx,int team,int way)
{
	int x,y,speed,skill;
	
	if(way>360) {
		x = 0;
		y = 0;
	}
	else {
		if(objectp(me))
			skill = me->query_skill("sailing",1);
		else
			skill = 0;
		speed = sea[idx][sprintf("speed%d",team)] * (600+skill)/600;
		x = sin(way*PI/180) * speed; 
		y = cos(way*PI/180) * speed;
	}
	
	sea[idx][sprintf("tx%d",team)] = x;
	sea[idx][sprintf("ty%d",team)] = y;
	sea[idx][sprintf("way%d",team)] = way;
	return 1;
}

protected string showship(int idx,int team)
{
	int hp;
	string color;
	
	hp = sea[idx][sprintf("hp%d",team)];
	if(hp>80) color = HIG;
	else if(hp>60) color = GRN;
	else if(hp>45) color = HIY;
	else if(hp>30) color = YEL;
	else if(hp>15) color = HIR;
	else color = RED;
	
	if( sea[idx][sprintf("ship%d",team)]->query_mode()==1 )
		return color+"��"NOR;
	else
		return color+"��"NOR;
}

void look(object me,int idx,int team,int way)
{
	int x,y,i,j,k,a,cur,size,tsize,x1,x2,y1,isshow;
	string str;
	
	if(!me || !userp(me)) return;
	
	if(team==1) {
		x = sea[idx]["x2"] - sea[idx]["x1"];
		y = sea[idx]["y2"] - sea[idx]["y1"];
	}
	else {
		x = sea[idx]["x1"] - sea[idx]["x2"];
		y = sea[idx]["y1"] - sea[idx]["y2"];
	}
	
	// get ruler
	size = 1;
	switch(way) {
		case 6: if(x<0) size = 0; break;
		case 4: if(x>0) size = 0; break;
		case 8: if(y<0) size = 0; break;
		case 2: if(y>0) size = 0; break;
	}

	i = MAX( ABS(x) , ABS(y) );
	if( i > 7500 || size == 0 ) { size = 1000; str = "һ"; }
	else if( i > 3750 ) { size = 500; str = "��"; }
	else if( i > 1875 ) { size = 250; str = "�ķ�֮һ"; }
	else { size = 125; str = "�˷�֮һ"; }
	
	x /= size;
	y /= size;
	
	// get shot to be showed
	tsize = 0;
	for(i=0;i<MAX_SHOTS;i++) {
		if( shot[i]["x"]==0 || shot[i]["job"]!=idx ) continue;
	
		if(team==1) {
			tshot[tsize]["x"] = shot[i]["x"] - sea[idx]["x1"];
			tshot[tsize]["y"] = shot[i]["y"] - sea[idx]["y1"];
		}
		else {
			tshot[tsize]["x"] = shot[i]["x"] - sea[idx]["x2"];
			tshot[tsize]["y"] = shot[i]["y"] - sea[idx]["y2"];
		}
		
		tshot[tsize]["x"] /= size;
		tshot[tsize]["y"] /= size;
		tshot[tsize]["team"] = shot[i]["team"];
		
		switch(way) {
			case 6: if(tshot[tsize]["x"]>0 && ABS(tshot[tsize]["y"])<15) tsize++; break;
			case 4: if(tshot[tsize]["x"]<0 && ABS(tshot[tsize]["y"])<15) tsize++; break;
			case 8: if(tshot[tsize]["y"]>0 && ABS(tshot[tsize]["x"])<15) tsize++; break;
			case 2: if(tshot[tsize]["y"]<0 && ABS(tshot[tsize]["x"])<15) tsize++; break;
		}
	}
		
	// first line
	isshow = 1;
	switch(way) {
		case 6: 
			tell_object(me,CYN"����������ȥ��\n"NOR);
			tell_object(me,"  010203040506070809101112131415\n");
			if(x<1 || x>15) isshow = 0;
			x1 = 0; x2 = 30; y1 = -15;
			break;
		case 4: 
			tell_object(me,CYN"����������ȥ��\n"NOR);
			tell_object(me,"  151413121110090807060504030201\n"); 
			if(x<-15 || x>-1) isshow = 0;
			x1 = 30; x2 = 30; y1 = -15;
			break;
		case 8: 
			tell_object(me,CYN"����������ȥ��\n"NOR);
			tell_object(me,"  151413121110090807060504030201**010203040506070809101112131415\n");
			if(x<-15 || x>15) isshow = 0;
			x1 = 30; x2 = 62; y1 = 1;
			break;
		case 2: 
			tell_object(me,CYN"�����Ϸ���ȥ��\n"NOR);
			tell_object(me,"  151413121110090807060504030201"+showship(idx,team)+"010203040506070809101112131415\n");
			if(x<-15 || x>15) isshow = 0;
			x1 = 30; x2 = 62; y1 = 1;
			break;
	}
		
	a = -1;
	for(k=15;k>=y1;k--) {
		if(way==2) i=k-16; else i=k;
		if(i==0 && way==6)	
			tell_object(me,showship(idx,team));
		else
			tell_object(me,sprintf("%.2d",ABS(i)));
		cur = 0;
		
		for(j=0;j<tsize;j++) {
			if( tshot[j]["y"] != i ) continue;
			
			if(cur>0) tell_object(me,ANSI_CHAR+sprintf("%d",cur)+ANSI_LEFT);
			cur = x1 + tshot[j]["x"]*2;
			tell_object(me,ANSI_CHAR+sprintf("%d",cur)+ANSI_RIGHT);	
			
			if(tshot[j]["team"]==1) tell_object(me,HIW); else tell_object(me,CYN);
			tell_object(me,"��"NOR);
			cur += 2;
		}
		
		if( y==i && isshow ) a = 0;
				
		if(cur<x2) tell_object(me,ANSI_CHAR+sprintf("%d",x2-cur)+ANSI_RIGHT);
		if(i==0 && way==4)	
			tell_object(me,showship(idx,team)+"\n");
		else
			tell_object(me,sprintf("%.2d\n",ABS(i)));
		
		if(a>=0) a++;
	}

/*
	for(k=15;k>=y1;k--) {
		if(way==2) i=k-16; else i=k;
		if(i==0 && way==6)	
			tell_object(me,showship(idx,team));
		else
			tell_object(me,sprintf("%.2d",ABS(i)));
		cur = 0;
		
		for(j=0;j<tsize;j++) {
			if( tshot[j]["y"] != i ) continue;
			
			if(cur>0) tell_object(me,ANSI_CHAR+sprintf("%d",cur)+ANSI_LEFT);
			cur = x1 + tshot[j]["x"]*2;
			tell_object(me,ANSI_CHAR+sprintf("%d",cur)+ANSI_RIGHT);	
			
			if(tshot[j]["team"]==1) tell_object(me,HIW); else tell_object(me,CYN);
			tell_object(me,"��"NOR);
			cur += 2;
		}
		
		if( y==i && isshow ) {
			if(cur>0) tell_object(me,ANSI_CHAR+sprintf("%d",cur)+ANSI_LEFT);
			cur = x1 + x*2;
			if(cur>0) tell_object(me,ANSI_CHAR+sprintf("%d",cur)+ANSI_RIGHT);
			tell_object(me,showship(idx,3-team));
			cur += 2;
		}
		
		if(cur<x2) tell_object(me,ANSI_CHAR+sprintf("%d",x2-cur)+ANSI_RIGHT);
		if(i==0 && way==4)	
			tell_object(me,showship(idx,team)+"\n");
		else
			tell_object(me,sprintf("%.2d\n",ABS(i)));
	}
*/	
	// last line
	switch(way) {
		case 6: tell_object(me,"  010203040506070809101112131415\n"); break;
		case 4: tell_object(me,"  151413121110090807060504030201\n"); break;
		case 8: tell_object(me,"  151413121110090807060504030201"+showship(idx,team)+"010203040506070809101112131415\n"); break;
		case 2: tell_object(me,"  151413121110090807060504030201**010203040506070809101112131415\n"); break;
	}

	// show ruler
	tell_object(me,"���Ϊ��"+str+" ��ÿ��λ��");
	if(wizardp(me) && me->query("env/test"))
		tell_object(me,sprintf("    ��һ��%d,%d ; ������%d,%d",sea[idx]["x1"],sea[idx]["y1"],sea[idx]["x2"],sea[idx]["y2"]));
	tell_object(me,"\n");
	
	// show ship
	if( a > 0 ) {
		tell_object(me,ANSI_CHAR+sprintf("%d",a+2)+ANSI_UP);
		
		if(y==0 && way==6)	
			tell_object(me,showship(idx,team));
		else
			tell_object(me,"��");

		cur = x1 + x*2;
		if(way==6) cur-=2;
		if(cur>0) tell_object(me,ANSI_CHAR+sprintf("%d",cur)+ANSI_RIGHT);
		tell_object(me,showship(idx,3-team));
		cur += 2;
		
		if(cur<x2) tell_object(me,ANSI_CHAR+sprintf("%d",x2-cur)+ANSI_RIGHT);
		if(y==0 && way==4)	
			tell_object(me,showship(idx,team)+"\n");
		else
			tell_object(me,"��\n");

		tell_object(me,ANSI_CHAR+sprintf("%d",a+1)+ANSI_DOWN);
	}
}

void fire(object me,int idx,int team,int angle,int elevation)
{
	int i,x,y,skill;
	
	for(i=0;i<MAX_SHOTS;i++)
		if( shot[i]["x"] == 0 ) break;
	if(i>=MAX_SHOTS) return;
	
	shot[i]["me"] = me;
	shot[i]["job"] = idx;
	shot[i]["team"] = team;
	shot[i]["x"]  = sea[idx][sprintf("x%d",team)];
	shot[i]["y"]  = sea[idx][sprintf("y%d",team)];
	shot[i]["time"] = (90-elevation) / SHOT_TIME;
	
	if(objectp(me))
		skill = me->query_skill("gunnery",1);
	else
		skill = 0;
	shot[i]["precision"] = (38 - shot[i]["time"])*100 / 45 * (600+skill)/600;
	if(shot[i]["precision"]<5)   shot[i]["precision"]=5;
	if(shot[i]["precision"]>100) shot[i]["precision"]=100;
	
	x = sin(angle*PI/180) * SHOT_SPEED;
	y = cos(angle*PI/180) * SHOT_SPEED;
	shot[i]["sx"] = x;
	shot[i]["sy"] = y;
}

int dokill(int idx,int team,int player)
{
	object me,me2,ship,killer;
	
	me = sea[idx][sprintf("player%d%d",team,player)];
	me2 = sea[idx][sprintf("player%d%d",team,3-player)];
	ship = sea[idx][sprintf("ship%d",3-team)];
	
	if( !objectp(me) || !objectp(me2) ) return 0;
	if( environment(me)!=ship ) return 0;
	if( me->is_fighting() || sea[idx][sprintf("killer%d",player)]<=0 ) return 1;

	killer = new(__DIR__"fighter");
	killer->set_party((team==1?-1:1),-1);
	killer->do_copy(((me->query("combat_exp")>me2->query("combat_exp"))?me:me2));
	killer->set("target", me);
	killer->set("job",idx);
	killer->set("team",3-team);
	killer->set("score",40);
	killer->move(ship);
	if(ship->query_mode()==1) {
		killer->add("eff_qi",killer->query("max_qi")*2);
		killer->add("qi",killer->query("max_qi"));
		killer->add("eff_neili",killer->query("max_neili"));
		killer->add("neili",killer->query("max_neili"));
		killer->add("combat_exp",killer->query("combat_exp")/2);
		killer->add_temp("apply/parry",killer->query_skill("force")/2);
		killer->add_temp("apply/attack",killer->query_skill("force")/3);
	}
	
	sea[idx][sprintf("killer%d",player)]--;
	return 2;
}

void jump(object me,int idx,int team)
{
	int x,y;
	object me1,me2,ship;
	
	x = sea[idx]["x1"] - sea[idx]["x2"];
	y = sea[idx]["y1"] - sea[idx]["y2"];
	if( (x*x+y*y) > (250*250) ) {
		tell_object(me,"����ͼ���ϵд������Ǿ���̫Զ�ˣ���������ȥ��\n");
		return;
	}
	
	me1 = sea[idx][sprintf("player%d1",team)];
	me2 = sea[idx][sprintf("player%d2",team)];
	if( !objectp(me1) || !objectp(me2) || environment(me1)!=environment(me2) ) {
		tell_object(me,"���ǵ��������԰���\n");
		return;
	}
	ship = sea[idx][sprintf("ship%d",3-team)];
	if( me1->is_busy() || me2->is_busy() ) {
		tell_object(me,"������æ���أ�\n");
		return;
	}
	
	sea[idx]["tx1"] = 0;
	sea[idx]["ty1"] = 0;
	sea[idx]["way1"] = 10000;
	sea[idx]["tx2"] = 0;
	sea[idx]["ty2"] = 0;
	sea[idx]["way2"] = 10000;
	
	message_vision(CYN"$N����һԾ�����ϵд���\n"NOR,me1);
	message_vision(CYN"$N����һԾ�����ϵд���\n"NOR,me2);
	tell_room(ship,CYN+me1->query("name")+"���˹�����\n"NOR);
	tell_room(ship,CYN+me2->query("name")+"���˹�����\n"NOR);
	me1->move(ship);
	me2->move(ship);

	ship->check_kill();
}

void back(object me,int idx,int team)
{
	int x,y;
	object ship;
	
	x = sea[idx]["x1"] - sea[idx]["x2"];
	y = sea[idx]["y1"] - sea[idx]["y2"];
	if( (x*x+y*y) > (1000*1000) ) {
		tell_object(me,"���������Լ��Ĵ������Ǿ���̫Զ�ˣ���������ȥ��\n");
		return;
	}
	ship = sea[idx][sprintf("ship%d",3-team)];
	message_vision(CYN"$N����һԾ�����ؼ���ս����\n"NOR,me);
	tell_room(ship,CYN+me->query("name")+"���˹�����\n"NOR);
	me->move(ship);
}

void gain(int idx,int team,int score)
{
	sea[idx][sprintf("gain%d",3-team)] += score;
}

protected void dogo(int idx,int team)
{
	string s = "",t = sprintf("%d",team);
	
	sea[idx]["x"+t] += sea[idx]["tx"+t] + sea[idx]["windx"] + sea[idx]["waterx"];
	sea[idx]["y"+t] += sea[idx]["ty"+t] + sea[idx]["windy"] + sea[idx]["watery"];
	
	if( sea[idx]["x"+t] < sea[idx]["left"]   ) { sea[idx]["x"+t] = sea[idx]["left"];  s = "����"; }
	if( sea[idx]["x"+t] > sea[idx]["right"]  ) { sea[idx]["x"+t] = sea[idx]["right"]; s = "����"; }
	if( sea[idx]["y"+t] > sea[idx]["top"]    ) { sea[idx]["y"+t] = sea[idx]["top"];   s = "����"; }
	if( sea[idx]["y"+t] < sea[idx]["bottom"] ) { sea[idx]["y"+t] = sea[idx]["bottom"];s = "�ϱ�"; }
	
	if(s!="" && sea[idx]["team"+t]==1 && random(10)==5)
		tell_room(sea[idx]["ship"+t],HIR"��ͻȻ����"+s+"��Զ���д�Ƭ�İ��������ò���ϸ��������\n"NOR);
}

protected void sink(int idx,int team)
{
	object ship = sea[idx][sprintf("ship%d",team)];
	if( !ship || ship->query("mode")!=1 ) return;
	ship->change_mode();
	sea[idx][sprintf("hp%d",team)] = 1000;
	tell_room(ship,"���ǵ�ս�����Ͼ�Ҫ��û�ˣ�����ֻ���������塣\n");
	
	ship = sea[idx][sprintf("ship%d",3-team)];
	tell_room(ship,"�д������������˶��������塣\n");
}

protected void doshot(int idx)
{
	int x,y,job,team,damage,diff;
	object me,ship;
	string str,t;
	
	team = 3 - shot[idx]["team"];
	job = shot[idx]["job"];
	x  = shot[idx]["x"] - sea[job][sprintf("x%d",team)];
	y  = shot[idx]["y"] - sea[job][sprintf("y%d",team)];
	
	me = shot[idx]["me"];
	if(sea[job][sprintf("team%d",team)]==0) {
		ship = sea[job][sprintf("ship%d",3-team)];
		t = "�д�";
		diff = 0;
	}
	else {
		ship = sea[job][sprintf("ship%d",team)];
		t = "���ǵ�ս��";
		diff = DIFFICULTY;
	}
	
	if(me && wizardp(me) && me->query("env/test"))
		tell_object(me,sprintf("shot:%d,%d , distence:%d,%d \n",shot[idx]["x"],shot[idx]["y"],x,y));
	if( random(38)>shot[idx]["precision"] ) {
		x *= 5;
		y *= 5;
	}
	if( ABS(x)>1250 || ABS(y)>1250 || (x*x+y*y)>(1250*1250) || sea[job][sprintf("ship%d",team)]->query_mode()==2 ) {
		if( ABS(x)>5000 || ABS(y)>5000 || (x*x+y*y)>(5000*5000) )
			tell_room(ship,"ֻ���ڵ������˺��ʲô��û�д��У�\n");
		else
			tell_room(ship,sprintf("ֻ���ڵ������˺������"+t+"��Լˮƽ%d�ߡ���ֱ%d�ߣ�ʲô��û�д��У�\n",x,y));
		return;
	}

	diff = random(diff);
	if(sea[job][sprintf("way%d",team)]>360) diff = 0;
	damage = x*x+y*y + diff*diff;
	damage = MIN(damage,1250*1250);
	damage = ( (100 - damage*100/(1250*1250)) * shot[idx]["precision"] / 100 ) * 10/35;
	if(damage<1) damage=1;
	damage = MIN( sea[job][sprintf("hp%d",team)] , damage );
	sea[job][sprintf("hp%d",team)] -= damage;
	gain(job,team,damage);
	
	if(me && wizardp(me) && me->query("env/test"))
		tell_object(me,sprintf("�˺�:%d , �Է�״̬:%d\n",damage,sea[shot[idx]["job"]][sprintf("hp%d",team)]));
		
	if(damage<5) str = HIG"�ڵ���"+t+"�Ա�ը��ֻ�����Բ�����"+t+"��\n";
	else if(damage<10) str = GRN"�ڵ�����"+t+"��ը��"+t+"�ܵ�һ���ƻ���\n";
	else if(damage<15) str = HIY"�ڵ�����"+t+"��ǣ�"+t+"�ܵ���С���ƻ���\n";
	else if(damage<20) str = YEL"�ڵ�����"+t+"�װ壬"+t+"�ܵ��ܴ���ƻ���\n";
	else if(damage<25) str = HIR"�ڵ�����"+t+"��Φ�ˣ�"+t+"�ܵ�������ƻ�����\n";
	else str = RED"�ڵ�����"+t+"��ҩ�⣬"+t+"�ܵ��������ƻ�������\n";
	tell_room(ship,str);
	
	damage = sea[shot[idx]["job"]][sprintf("hp%d",team)];
	if(damage>80) str = HIG+t+"�ƺ�û���ܵ������ƻ���\n"NOR;
	else if(damage>60) str = GRN+t+"��״���ƺ�����á�\n"NOR;
	else if(damage>45) str = HIY+t+"�ܵ�һ�����ƻ��������м�������ˡ�\n"NOR;
	else if(damage>30) str = YEL+t+"�ܵ��ܴ���ƻ������װ嶼����ˣ�\n"NOR;
	else if(damage>15) str = HIR+t+"�ܵ�������ƻ�����������𣡣�\n"NOR;
	else str = RED+t+"����Φ���Ѿ������ˣ��������嶼���³��У�����\n"NOR;
	tell_room(ship,str);
		
	if( damage <= 0 ) sink(shot[idx]["job"],team);
}

protected void dofire(int idx)
{
	int job = shot[idx]["job"];
	shot[idx]["x"] += shot[idx]["sx"] + sea[job]["windx"];
	shot[idx]["y"] += shot[idx]["sy"] + sea[job]["windy"];
	shot[idx]["time"]--;

	if( shot[idx]["time"]<=0 ) {
		doshot(idx);
		shot[idx]["x"] = 0;
	}
}

protected void nature(int flag)
{
	int i,x,y;
	int * ways = ({ 0,225,180,135,270,10000,90,315,0,45 });
	
	if(random(3)!=1 && !flag) return;
	for(i=0;i<MAX_JOBS;i++) {
		if( sea[i]["playing"]!=1 ) continue;
		
		if(flag) {
			sea[i]["wind"]  = random(9) + 1;
			sea[i]["water"] = random(9) + 1;
			sea[i]["windspeed"]  = random(10) + 1;
			sea[i]["waterspeed"] = random(10) + 1;
		}
		
		if( random(6)<3 ) {
			sea[i]["wind"]  = random(9) + 1;
			sea[i]["water"] = random(9) + 1;
		}
		else {
			sea[i]["windspeed"]  = random(10) + 1;
			sea[i]["waterspeed"] = random(10) + 1;
		}	
		
		x = sin(ways[sea[i]["wind"]]*PI/180) * WIND_SPEED * sea[i]["windspeed"]/10; 
		y = cos(ways[sea[i]["wind"]]*PI/180) * WIND_SPEED * sea[i]["windspeed"]/10;
		sea[i]["windx"] = x;
		sea[i]["windy"] = y;
		
		x = sin(ways[sea[i]["water"]]*PI/180) * WATER_SPEED * sea[i]["waterspeed"]/10; 
		y = cos(ways[sea[i]["water"]]*PI/180) * WATER_SPEED * sea[i]["waterspeed"]/10;
		sea[i]["wayx"] = x;
		sea[i]["wayy"] = y;
	}
}

protected void ai(int idx,int team)
{
	int x,y,angle,elevation,distance;
	object ship;
	float f;
	
	x = sea[idx]["x2"] - sea[idx]["x1"];
	y = sea[idx]["y2"] - sea[idx]["y1"];
	if(team==1) {
		x = -x;
		y = -y;
	}

	if(x==0) {
		if(y>=0) angle = 0; else angle = 180;
	}
	else if(y==0) {
		if(x>=0) angle = 90; else angle = 270;
	}
	else {
		f = ABS(y);
		f /= ABS(x);
		angle = atan(f) *180/PI;
		if( x>0 && y>0 ) angle = 270 - angle;
		else if( x>0 && y<0 ) angle = 270 + angle;
		else if( x<0 && y<0 ) angle = 90 - angle;
		else angle = 90 + angle;
	}
	
	if( ABS(x)>3500 || ABS(y)>3500 || (x*x+y*y)>(3500*3500) ) {
		if( angle != sea[idx]["angle"] ) {
			go(0,idx,team,angle);
			sea[idx]["angle"] = angle;
		}
	}
	else {
		go(0,idx,team,10000);
		sea[idx]["angle"] = 10000;
	}
	
	ship = sea[idx][sprintf("ship%d",team)];
	if( ABS(x)<7500 && ABS(y)<7500 && ship->query_mode()==1 && (time()-sea[idx]["fire"])>FIRE_BUSY && (x*x+y*y)<(7500*7500) && (x*x+y*y)>(125*125) ) {
		sea[idx]["fire"] = time();
		distance = MAX(x*x+y*y,1250*1250);
		elevation = 90 - sqrt(distance)*SHOT_TIME / SHOT_SPEED;
		fire(0,idx,team,angle,elevation);
		tell_room(sea[idx][sprintf("ship%d",3-team)],"Զ���ƺ��п��ڵ����˹�����\n");
	}
}

protected void clear(int idx)
{
	int i;
	for(i=0;i<MAX_SHOTS;i++) {
		if( shot[i]["x"]==0 || shot[i]["job"]!=idx ) continue;
		shot[i]["x"] = 0;
	}
	sea[idx]["playing"] = 0;
}

protected void clearuser(int idx,string usr)
{
	sea[idx][usr]->delete_temp("seawar");
	sea[idx][usr] = 0;
}

protected int war_count = 0;
protected void war()
{
	int i,jobs = 0;
	
	remove_call_out("war");
	
	for(i=0;i<MAX_JOBS;i++) {
		if( sea[i]["playing"]!=1 ) continue;

		if( sea[i]["team1"]==1) {
			if(sea[i]["player11"] && userp(sea[i]["player11"]) && sea[i]["player11"]->is_ghost())
				clearuser(i,"player11");
			if(sea[i]["player12"] && userp(sea[i]["player12"]) && sea[i]["player12"]->is_ghost())
				clearuser(i,"player12");
			if( !objectp(sea[i]["player11"]) && !objectp(sea[i]["player12"]) ) {
				clear(i);
				continue;
			}
		}
		else {
			if(sea[i]["player21"] && userp(sea[i]["player21"]) && sea[i]["player21"]->is_ghost())
				clearuser(i,"player21");
			if(sea[i]["player22"] && userp(sea[i]["player22"]) && sea[i]["player22"]->is_ghost())
				clearuser(i,"player22");
			if( !objectp(sea[i]["player21"]) && !objectp(sea[i]["player22"]) ) {
				clear(i);
				continue;
			}
		}
		
		dogo(i,1);
		dogo(i,2);
		jobs++;
	}
	
	for(i=0;i<MAX_SHOTS;i++) {
		if( shot[i]["x"]==0 ) continue;
		dofire(i);
	}
	
	if( war_count % 2 ) {
		for(i=0;i<MAX_JOBS;i++) {
			if( sea[i]["playing"]!=1 ) continue;
			if( sea[i]["team1"]==0 ) ai(i,1);
			if( sea[i]["team2"]==0 ) ai(i,2);
		}
	}
	
	war_count++;
	if(war_count>5) {
		nature(0);
		war_count = 0;
	}
	
	if(jobs>0) call_out("war",1);
}
