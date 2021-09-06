// look.c ���°汾
// Modified by snowman@SJ 11/12/2000
// Inv ��ʾ�Ż����������ġ�
// modified by olives@SJ 4/21/2000
// ����һ��look�����������޹ص�bug
// query����
// modified by augx@sj 9/11/2001
// �����Ʒ�����ʾ

#include <room.h>
#include <ansi.h>
#include <combat.h>
#include <level.h>
#include <get_place.h>

inherit F_CLEAN_UP;

int look_room(object me, object env, int night);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string getper(object obj);
string tough_level(int power, int hide_level, int self);
string gettof(object obj, int self);
string getdam(object obj);
string inventory_look(object obj, int corpse, int equip);

void create() { seteuid(getuid()); }

nosave mapping to_chinses = ([
	"damage":"�˺���+$x",
	"armor":"������+$x",
	"strength":"����+$x",
	"constitution":"����+$x",
	"dexerity":"��+$x",
	"intelligence":"����+$x",
	"attack":"����+$x",
	"defense":"����+$x",
	"neili":"����+$x",
	"jingli":"����+$x",
	"jing":"��Ѫ+$x",
	"qi":"��Ѫ+$x",
	"re_qi":"��Ѫ�ָ��ٶ�+$x%",
	"re_neili":"�����ָ��ٶ�+$x%",
	"re_jing":"��Ѫ�ָ��ٶ�+$x%",
	"re_jingli":"�����ָ��ٶ�+$x%",
	"parry":"�м�+$x",
	"dodge":"�Ṧ+$x",
	"force":"�ڹ�+$x",
	"armor_vs_force":"�ڹ�����+$x",
]);

int main(object me, string arg)
{
	object obj;
	int result;

	if( !arg ) result = look_room(me, environment(me), NATURE_D->is_night());
	else if ((obj = present(arg, environment(me))) || (obj = present(arg, me))) {
		if( obj->is_character() ) result = look_living(me, obj);
		else result = look_item(me, obj);
	} else result = look_room_item(me, arg);

	return result;
}
void realtime_map(object me,object env)
{
        object room_obj;
        mapping exits;
    	int i;
        string map_room, map_room2,jiantou;
     	string *dirs;
        mapping alldirs=([      
                        "northwest" : "          ",
                        "north"     : "          ",
                        "northup"   : "          ",
                        "northeast" : "          ",
                        "west"      : "          ",
                        "east"      : "          ",
                        "southeast" : "          ",
                        "south"     : "          ",
                        "southwest" : "          ",
                        "southdown" : "          ",
                        "eastup" : "          ",
                        "southup" : "          ",
                        "northdown" : "          ",
                        "eastdown" : "          ",
                        "westup" : "          ",
                        "westdown" : "          ",
                        "enter" : "          ",
                        "out" : "          ",
                        "up" : "          ",
                        "down" : "          ",
                        "left" : "          ",
                        "right" : "          ",
                        ]);  
       if( mapp(exits = env->query("exits")) ) 
        {                       
                dirs=keys(exits);
                for(i=0;i< sizeof(dirs);i++)
                {
                        if(!room_obj=find_object(exits[dirs[i]]))
                                room_obj=load_object(exits[dirs[i]]);
                        if(room_obj){                                
                                if (room_obj->query("short"))
                                alldirs[dirs[i]]=room_obj->query("short");                              ;
                                }
        
                }
        
                jiantou="  ";
                map_room2=alldirs["enter"];
                if(alldirs["enter"]!="          "){
                        map_room2=alldirs["enter"];
                        jiantou=HIR+"��"+NOR;
                        }
                if(alldirs["up"]!="          "){
                        map_room2=alldirs["up"];
                        jiantou=HIC+"��"+NOR;
                        }
                if(alldirs["northdown"]!="          "){
                        map_room2=alldirs["northdown"];
                        jiantou="��";
                        }
                if(alldirs["northup"]!="          "){
                        map_room2=alldirs["northup"];
                        jiantou="��";
                        }
                if(alldirs["north"]!="          "){
                        map_room2=alldirs["north"];
                        jiantou="��";
                        }
                map_room=map_room2;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                map_room =map_room+" ";
                                map_room =" "+map_room;
                        }
                printf("             %10s  %7s  %6s\n",
                alldirs["northwest"],map_room,alldirs["northeast"]);
                
                printf("                        %s   %s   %s\n",
                alldirs["northwest"]=="          " ? "  ":"�I",
                jiantou,
                alldirs["northeast"]=="          " ? "  ":"�J");
                
                jiantou="  ";
                map_room2=alldirs["westdown"];
                if(map_room2!="          ")
                                jiantou="��";
                if(alldirs["left"]!="          "){
                        map_room2=alldirs["left"];
                        jiantou="��";
                        }
                if(alldirs["westup"]!="          "){
                        map_room2=alldirs["westup"];
                        jiantou="��";
                        }
                if(alldirs["west"]!="          "){
                        map_room2=alldirs["west"];
                        jiantou="--";
                        }
                printf("             %10s%s",map_room2,jiantou);        
                map_room2=env->query("short") ? env->query("short"): "----------";
                map_room=HIG+map_room2+NOR;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                if(alldirs["east"]=="          ")
                                map_room =map_room + " ";
                                else map_room=map_room + "-";
                                if(alldirs["west"]=="          ")
                                map_room =" "+ map_room;
                                else map_room ="-"+map_room;
                        }
                printf("%8s",map_room);
                
                jiantou="  ";
                map_room2=alldirs["eastup"];
                if(map_room2!="          ")
                                jiantou="��";
                if(alldirs["right"]!="          "){
                        map_room2=alldirs["right"];
                        jiantou="��";
                        }
                if(alldirs["eastdown"]!="          "){
                        map_room2=alldirs["eastdown"];
                        jiantou="��";
                        }
                if(alldirs["east"]!="          "){
                        map_room2=alldirs["east"];
                        jiantou="--";
                        }
                
                printf("%s%-10s\n",jiantou,map_room2);
                
                jiantou="  ";
                map_room2=alldirs["out"];
                if(alldirs["out"]!="          "){
                        map_room2=alldirs["out"];
                        jiantou=HIR+"��"+NOR;
                        }
                if(alldirs["down"]!="          "){
                        map_room2=alldirs["down"];
                        jiantou=HIC+"��"+NOR;
                        }
                
                if(alldirs["southdown"]!="          "){
                                map_room2=alldirs["southdown"];
                                jiantou="��";
                                }
                if(alldirs["southup"]!="          "){
                        map_room2=alldirs["southup"];
                        jiantou="��";
                        }
                if(alldirs["south"]!="          "){
                        map_room2=alldirs["south"];
                        jiantou="��";
                        }
                map_room=map_room2;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                map_room =map_room + " ";
                                map_room =" "+map_room;
                        }
                printf("                        %s   %s   %s\n",
                alldirs["southwest"]=="          " ? "  ":"�L",
                jiantou,
                alldirs["southeast"]=="          " ? "  ":"�K");
                printf("             %10s  %7s  %6s\n",
                alldirs["southwest"],map_room,alldirs["southeast"]);
                
                        
        }       
        else
        {
                map_room2=env->query("short") ? env->query("short"): "----------";
                map_room=HIG+map_room2+NOR;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                if(alldirs["east"]=="          ")
                                map_room =map_room + " ";
                                else map_room=map_room + "-";
                                if(alldirs["west"]=="          ")
                                map_room =" "+ map_room;
                                else map_room ="-"+map_room;
                        }
                printf("\n                            %s\n",map_room);
                
        }
        return;
}
int look_room(object me, object env, int night)
{
	int i;
	int * dirs2d = ({ 0,0,0,0,0,0,0,0,0,0,0 });
	object *inv;
	mapping exits;
	string str, *dirs, arg;

	if( !env ) {
		write("������ܻ����ɵ�һƬ��ʲôҲû�С�\n");
		return 1;
	}
	// night ^_^ , added by snowman@SJ
	if (env->query("no_light")
	&& !env->query_night_light()
	&& random(me->query_con()) < 35) {
		if(env->query("night_long")) str = env->query("night_long");
		else str = "����һƬ��ڣ�����Ȼ�������۾���ϸ�ۿ����ɻ��ǿ��������Χ��\n"+
			"���һ�ж��������ںڰ�֮�У����ֲ�����ָ... \n";
	} else if (env->query("outdoors") && night
	&& environment(me) != env
	&& !env->query_night_light()
	&& random(me->query_con()) < 35) {
		if(env->query("night_long")) str = env->query("night_long");
		else str = "ҹ���ˣ�����Ȼ�������۾���ϸ�ۿ����ɻ��ǿ��������Χ�����\n"+
			"һ�ж���ҹɫ�����֣������µĵ�·��ģ��������... \n";
	}

	str = sprintf( "%s - %s\n    %s%s",
		env->query("short"),
		wizardp(me)? file_name(env): "",
		str?str:env->query("long"),
		env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

	// Client Send
	if( me && userp(me) && CLIENT_D->IsClient(me) ) {
		CLIENT_D->SendRoomLong(me,str);
		str = "";
	}
	
	if (!mapp(exits = env->query("exits")))
		exits = ([ ]);

	if (me->query("env/newlook")) {
		dirs = keys(exits);
		for (i=0; i<sizeof(dirs); i++)
			if (env->query_door(dirs[i], "status") & DOOR_CLOSED)
				dirs[i] = 0;
		dirs -= ({ 0 });
		if (sizeof(dirs) < 1)
			str += "    ����û���κ����Եĳ�·��\n";
		else if ((env->query("no_light")
		|| (night && environment(me) != env && env->query("outdoors")))
		&& !env->query_night_light() && random(me->query_con()) < 15) {
			i = random(sizeof(dirs));
			if (random(me->query_con()) < 10) str += "    ���￴�����κ����Եĳ�·��\n";
			else str += "    ���￴�ü���Ψһ������ " + BOLD + dirs[i] + NOR + "��\n";
		} else {
			for(i=0; i<sizeof(dirs); i++) {
				switch (dirs[i]) {
					case "east"      : dirs2d[0]=1; break;
					case "southeast" : dirs2d[1]=1; break;
					case "south"     : dirs2d[2]=1; break;
					case "southwest" : dirs2d[3]=1; break;
					case "west"      : dirs2d[4]=1; break;
					case "northwest" : dirs2d[5]=1; break;
					case "north"     : dirs2d[6]=1; break;
					case "northeast" : dirs2d[7]=1; break;
					case "up"        : dirs2d[8]=1; break;
					case "down"      : dirs2d[9]=1; break;
					case "enter" 	 : dirs2d[10]=1; break;
					default: continue;
				}
				dirs -= ({ dirs[i] });
				i--;
			}

			if(dirs2d[8])  str+=HIR+"   up  \n"NOR;
			if(dirs2d[5])  str+=HIR; str += "nw "NOR;
			if(dirs2d[6])  str+=HIR; str += "n "NOR;
			if(dirs2d[7])  str+=HIR; str += "ne\n"NOR;
			if(dirs2d[4])  str+=HIR; str += "w  "NOR;
			if(dirs2d[10]) str+=HIR; str += "r "NOR;
			if(dirs2d[0])  str+=HIR; str += " e"NOR;

			if(sizeof(dirs)==1)
				str += "    ���������� " + BOLD + dirs[0] + NOR + "��\n";
			else if(sizeof(dirs)> 1)
				str += sprintf("    ���������� "+BOLD+"%s"+NOR+" �� "+BOLD+"%s"+NOR+ "��\n", implode(dirs[0..<2], "��"), dirs[<1]);
			else str += "\n";

			if(dirs2d[3])  str+=HIR; str += "sw "NOR;
			if(dirs2d[2])  str+=HIR; str += "s "NOR;
			if(dirs2d[1])  str+=HIR; str += "se\n"NOR;
			if(dirs2d[9])  str+=HIR"  down  \n"NOR;
		}
	} else {
		dirs = sort_array(keys(exits), 1);
		for (i=0; i<sizeof(dirs); i++)
			if (env->query_door(dirs[i], "status") & DOOR_CLOSED)
				dirs[i] = 0;
		dirs -= ({ 0 });
		if (sizeof(dirs) < 1)
			str += "    ����û���κ����Եĳ�·��\n";
		// night ^_^ , added by snowman@SJ
		else if ((env->query("no_light")
		|| (night && environment(me) != env && env->query("outdoors")))
		&& !env->query_night_light() && random(me->query_con()) < 35) {
			i = random(sizeof(dirs));
			if (random(me->query_con()) < 10) str += "    ���￴�����κ����Եĳ�·��\n";
			else if (random(me->query_con()) < 20)
				str += "    ���￴�ü���Ψһ������ " + BOLD + dirs[i] + NOR + "��\n";
			else str += sprintf("    ���￴����ĳ����� " + BOLD + "%s" + NOR + "��\n", implode(dirs[0..i], "��"));
		}
		// hehehe.....
		else if( sizeof(dirs)==1 ) str += "    ����Ψһ�ĳ����� " + BOLD + dirs[0] + NOR + "��\n";
		else str += sprintf("    �������Եĳ����� " + BOLD + "%s" + NOR + " �� " + BOLD + "%s" + NOR + "��\n",
			implode(dirs[0..<2], "��"), dirs[<1]);
	}

	env->delete("move_desc");

	inv = all_inventory(env);
	exits = ([]);
	for (i=0; i<sizeof(inv); i++) {
		if( inv[i]==me ) continue;
		if( !me->visible(inv[i]) ) continue;

		// night.
		if ((env->query("no_light") || (night && env->query("outdoors") && environment(me) != env))
		&& !env->query_night_light()
		&& random(me->query_con()) < 35
		&& !inv[i]->is_character()
		&& !inv[i]->query("location")) continue;
		// hehehehehehe.....
		if (userp(inv[i])) {
			str += "  " + inv[i]->short() + "\n";
			continue;
		}
		arg = base_name(inv[i]) + inv[i]->short();
		if (!mapp(exits[arg])) {
			exits[arg] = ([
				"total" : 1,
				"unit" : (inv[i]->query("unit")?inv[i]->query("unit"):"��"),
				"short" : inv[i]->short(),
			]);
		}
		else exits[arg]["total"]++;
	}
	if (me->query("env/look")){
		string place_name = get_place(file_name(env));
		if(place_name && place_name!="" && place_name!="��ԭ����" ) write("��������������" HIG+ place_name + NOR+"��\n");
		realtime_map(me,env);
	}
	
	dirs = keys(exits);
	if (!sizeof(dirs)) {
		write(str);	
		return 1;
	}
	for (i = 0; i < sizeof(dirs); i++) {
		if (exits[dirs[i]]["total"] > 1)
			arg = "  " + chinese_number(exits[dirs[i]]["total"]) + exits[dirs[i]]["unit"] + exits[dirs[i]]["short"];
		else arg = "  " + exits[dirs[i]]["short"];
		str += arg + "\n";
	}

	write(str);
	return 1;
}

int look_item(object me, object obj)
{
	mixed *inv;
	string prep;
	mapping skill;
	int i;
	string look_msg = "";
	string sn,num;	
       	float numa;
	
	write(obj->long());

	if(mapp(skill = obj->query("skill")))
        {        	
                sn = to_chinese(skill["name"]);                
                if(!undefinedp(skill["exp_required"])){
                	if (skill["exp_required"] == 0)
                		look_msg += "�޾���ֵҪ��\n";
                	else
                        	look_msg += sprintf("����Ҫ�� %d �㾭��ֵ\n", skill["exp_required"]);
		
		}
                if(!undefinedp(skill["min_skill"]))
                        look_msg += sprintf("��%s������Ҫ�� %d ��\n", sn,skill["min_skill"]);
                
                if(!undefinedp(skill["difficulty"]))
                        look_msg += sprintf("����Ҫ�� %d ������\n", skill["difficulty"]);
                
                if(!undefinedp(skill["max_skill"]))
                        look_msg += sprintf("����ѧϰ��%s���� %d ��\n", sn, skill["max_skill"]);
                if(look_msg != "") 
                write(HIG"һ�Ź�׭��д�š�"+obj->query("name")+"��ѧϰҪ��\n"NOR
                	+
                	"����������������������������������\n"
                	+look_msg+
                	"����������������������������������\n");
        }        
        if(mapp(obj->query("material_prop")) || mapp(obj->query("material_props")))
        {               
                look_msg ="";
           	if(mapp(skill = obj->query("material_prop")))
           	{
           	inv = keys(skill);
                for(i=0;i<sizeof(inv);i++){
                	sn = to_chinses[inv[i]];
                	sn = replace_string(sn,"$x",sprintf("%d",skill[inv[i]]));                	
                	look_msg += HIG"\t"+sn+"\n"NOR;
                }
                }                
                if(mapp(skill = obj->query("material_props")))
           	{
           	inv = keys(skill);
                for(i=0;i<sizeof(inv);i++){
                	sn = skill[inv[i]];                	
                	sscanf(sn,"status_type%*sjade_show%sitem_show%*sadd_num%scan_wield%*s",sn,num);
                	if(sn==" ") continue;
                	if(stringp(num)) sscanf(num,"%f",numa);
                	else continue;
                	sn = replace_string(sn,"$x",sprintf("%d",to_int(numa)));
                	look_msg += HIG"\t"+sn+"\n"NOR;
                }
                }
		if(look_msg != "") 
                write(HIG"һ�Ź�׭��д�š�"+obj->query("name")+HIG"�����幦�ܣ�\n"NOR
                	+
                	"����������������������������������\n"
                	+look_msg+
                	"����������������������������������\n");
        }       	
	if( !(int)obj->query("broken") && (i = (int)obj->query("dur")) ) {
		if(i>1500) write("������û��ʲô�𻵡�\n");
		else if(i>750) write("�������Ѿ�ʹ�ù�һ��ʱ���ˡ�\n");
		else if(i>200) write("��������Ҫ�����ˡ�\n");
		else write("���������Ͼ�Ҫ���ˡ�\n");
	}
	inv = all_inventory(obj);
	if( !obj->is_closed() && sizeof(inv)) {
		switch( (string)obj->query("prep") ) {
			case "on":prep = "��";break;
			case "under":prep = "��"; break;
			case "behind":prep = "��";break;
			case "inside":prep = "��";break;
			default:prep = "��";
		}
		inv = map_array(inv, "inventory_look", this_object(), 1);
		write(sprintf("%s���У�\n  %s\n", prep, implode(inv, "\n  ")));
	}
	return 1;
}

string getper(object obj)
{
	int per, age;

	string str;

	per = obj->query_per();
   //   age = obj->query("str"); ����str?����ͷ�ɣ�
	age = obj->query("age");

	if (obj->query("gender") == "Ů��") {
		if (per >= 40) str = "�������ף����޾��ף�ò������ʤ���֣�";
		else if (per >= 37) {
			if (age > 22) str = "�촽��Ϳһ��죬����һЦ��������";
			else str = "�������ף�������࣬���续�����ɣ�";
		} else if (per >= 33) {
			if (age > 22) str = "��ò���������ʸ��ţ������˼����ӣ�";
			else str = "��ò������毻���ˮ�������˼����ӣ�";
		} else if (per >= 30) {
			if (age > 22) str = "�������裬����ˮ�ӣ���ò������";
			else str = "��ۼ���ף�һЦ��ǣ���Ц�����";
		} else if (per >= 27) str = "�߻����£��������ɣ�";
		else if (per >= 24) str = "������ò�����Ľ��Σ�";
		else if (per >= 20) str = "�������ˣ��м�����ɫ��";
		else if (per >= 17) str = "��òƽӹ������һ�㡣";
		else if (per >= 14) str = "���Ųλ��ò�����Ρ�";
		else str = "һ����Ϳ������������";
	} else {
		if (per >= 40) str = "Ӣ�˲�����һ���˲ţ���Ϊ����������һ�ˣ�";
		else if (per >= 37) str = "�����ٷ磬�������Σ����ƾ������У�";
		else if (per >= 33) str = "���㿡�ţ���ò�Ƿ��������������";
		else if (per >= 30) {
			if (age < 16) str = "ò����Ů�����������������磡";
			else  str = "ò���˰����ݱ������Ǳ����ã�";
		}
		else if (per >= 27) str = "��ò���ڣ��������У�";
		else if (per >= 24) str = "Ӣ�����������ʷǷ���";
		else if (per >= 20) str = "��ٶ�������òƽƽ��";
		else if (per >= 17) str = "��ٲ������������ӡ�";
		else if (per >= 14) str = "ţ��¿������Ŀ������";
		else str = "�����׹��·����˽䷵�꣡";
	}
	return "����" + str + "\n";
}

string gettof(object ob, int self)
{
	object weapon;
	string skill_type;
	int attack_points, hide_level;
	mapping prepare;

	if (objectp(weapon = ob->query_temp("weapon"))) skill_type = weapon->query("skill_type");
	else {
		prepare = ob->query_skill_prepare();
		if (!sizeof(prepare)) skill_type = "unarmed";
		else skill_type = keys(prepare)[0];
	}

	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);

	if (intp(hide_level = ob->query_temp("hide_level")) && hide_level > 0)
		return tough_level(attack_points, hide_level, 0);
	return tough_level(attack_points, 0, self);
}

int look_living(object me, object obj)
{
	int age;
	string str, pro;
	mixed *inv;

	if( me != obj && obj->visible(me)) {
		if (wizardp(obj))
			tell_object(obj, "("+capitalize(me->query("id"))+")");
		tell_object(obj, me->name() + "�������㿴����֪����Щʲô���⡣\n");
	}

	inv = explode(obj->long(), "\n");
	if (sizeof(inv) > 10) {
		str = implode(inv[0..8], "\n") + "\n";
		str += "�˴�ɾȥ"+chinese_number(sizeof(inv)-9)+"�С�\n";
	} else str = implode(inv, "\n") + "\n";

	pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

	if (!obj->query_temp("apply/long")) {
		if( (string)obj->query("race")=="����"
		&& intp(age = obj->query("age"))
		&& !obj->query("no_head")) {
			if (obj->query("gender") != "����"
			&& obj->query_skill("beauty") > 34) {
				int temp_age = (obj->query_skill("beauty") - 30) / 5;

				if (temp_age > age / 2)
					temp_age = age / 2;
				age -= temp_age;
			}
			if (age < 10) str += sprintf("%s����������ʮ��", pro);
			else str += sprintf("%s������Լ%s����", pro, chinese_number(age / 10 * 10));
			if (wizardp(me) || userp(obj) && obj->query("age") >= 16) str += "��" + getper(obj);
			else str += "��\n";
			if (obj==me || wizardp(me)) age = 1;
			else age = 0;
			// add by snowman@SJ 28/02/2000
			if(!obj->is_corpse())
				if (living(obj) && (me->query("combat_exp") > obj->query("combat_exp")/3*2 || me==obj))
				str +=sprintf("%s�����տ���ȥ", pro) + gettof(obj, age) +"�������ƺ�" + getdam(obj) +"��\n";
				else str += pro+"���书��������ǳ��\n";
		}
		// Modified by snowman@SJ 04/04/2000. move family check to rankd.c
		if (obj != me && userp(obj))
			str += pro + "�����"+RANK_D->query_family_close(me, obj)+"��\n";

		if (userp(obj) && obj->query("id") == me->query("marry/id"))
			str += pro + "�����"
				+ (obj->query("gender") == "Ů��"?"����":"���")
				+ "��\n";
		else if (obj->query_temp("marry") == me)
			str += pro + "�����δ��"
			+ (obj->query("gender") == "Ů��"?"��":"��") + "��\n";
	}

	if (obj->query("max_qi")) {
		int eratio = (obj->query("eff_qi")+obj->query_temp("apply/qi")) * 100
				/ (obj->query("max_qi")+obj->query_temp("apply/qi"));
		int sratio;
				
		if( obj->query("eff_qi")+obj->query_temp("apply/qi")>0 ) sratio = obj->query("qi") * 100 / (obj->query("eff_qi")+obj->query_temp("apply/qi"));
		
		else sratio=0;
		
		if (sratio < eratio)
			str += pro + COMBAT_D->status_msg(
				obj->query("qi") * 100 / (obj->query("max_qi")+obj->query_temp("apply/qi"))) + "\n";
		else
			str += pro + COMBAT_D->eff_status_msg(eratio) + "\n";
	}

	inv = all_inventory(obj);
	inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse());
	inv -= ({ 0 });
	if( sizeof(inv) )
		str += sprintf( obj->is_corpse() ? "%s�������У�\n%s\n" : "%s�����ţ�\n%s\n",
			pro, implode(inv, "\n") );
//	else if (me != obj && obj->query("race")=="����")
//		str += pro + "����û���κδ�����\n";
	inv = ({ obj->query_temp("weapon") });
	inv -= ({ 0 });
	if( sizeof(inv) ) str += sprintf("%sװ���ţ�\n%s\n",pro, inventory_look(inv[0], 0, 1));
//	else if (me != obj && obj->query("race")=="����")
//		str += pro + "����û���κ�װ����\n";

	write(str);

	if (obj != me && obj->visible(me) && userp(me) && living(obj)
	&& !(userp(me) && userp(obj) && me->query("marry/id") == obj->query("id"))
	&& obj->query("shen") < -me->query_int() * 100 ) {
		if( (int)obj->query("combat_exp") > (int)me->query("combat_exp")){
			write(obj->name() + "ͻȻת��ͷ������һ�ۡ�\n");
			COMBAT_D->auto_fight(obj, me, "berserk");
		}
		else write(obj->name() + "ͻȻת��ͷ�������㼸�ۡ�\n");
	}
	return 1;
}

string inventory_look(object obj, int corpse, int equip)
{
	string str;

	if( obj->query("equipped")) {
		if (corpse || (!equip && !obj->query("weapon_prop"))
		|| (equip && obj->query("weapon_prop")))
		    str = HIC "  ��" NOR + obj->short();
		else return 0;
	}
	else if( obj->query("embedded") && !corpse && !equip)  str = HIR "  ��" NOR + obj->short();
	else if( corpse )
		str = "    " + obj->short();
	else return 0;
	return str;
}


int look_room_item(object me, string arg)
{
	object env;
	mapping item, exits;

	if (!objectp(env = environment(me)))
		return notify_fail("������˻����ɵ�һƬ��ʲôҲû�С�\n");
	if (mapp(item = env->query("item_desc")) && !undefinedp(item[arg])) {
		if (stringp(item[arg]))
			write(item[arg]);
		else if (functionp(item[arg]))
			write((string)(*item[arg])(me));
		return 1;
	}
	if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
		if( objectp(env = load_object(exits[arg])) )
			look_room(me, env, NATURE_D->is_night());
		else return notify_fail("��������޷����壬�뱨����ʦ��\n");
		return 1;
	}
	return notify_fail("��Ҫ��ʲô��\n");
}

string *tough_level_desc = ({ LEVEL });

string tough_level(int power, int hide_level, int self)
{
	int lvl, rawlvl;

	if (power < 0) power = 0;
	//power *= 10;
	rawlvl = to_int(pow((float)1.0 * power, 0.236));
        lvl = rawlvl;
//        lvl = to_int(rawlvl/1.5);
//        rawlvl = to_int(rawlvl/1.5);
	if (hide_level) lvl = hide_level;
	if (rawlvl >= sizeof(tough_level_desc)) rawlvl = sizeof(tough_level_desc)-1;
	if (lvl >= sizeof(tough_level_desc)) lvl = sizeof(tough_level_desc)-1;

	return tough_level_desc[self?rawlvl:lvl];
}

string getdam(object obj)
{
	int level;
	string *heavy_level_desc= ({"����","����","����","����","����","����",});

	level = obj->query("jiali");
	level += obj->query_temp("apply/damage")/3;  // weapon ����Ч������ unarmed / 3

	level /= 30;
	if( level >= sizeof(heavy_level_desc) ) level = sizeof(heavy_level_desc)-1;
	return heavy_level_desc[level];
}

int help (object me)
{
	write(@HELP
ָ���ʽ: look [<��Ʒ>|<����>|<����>]

���ָ������鿴�����ڵĻ�����ĳ����Ʒ��������Ƿ���

Ӱ�������Ļ���������
set brief 1/0 : ��/��ϸ ��ʾ��������
set newlook 1/0 : ֱ��/���� ��ʾ����

HELP
);
	return 1;
}
