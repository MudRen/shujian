// By Spiderii  ����TB����
// By Spiderii �����жϣ�fix dzd ����srf��bug ....
#define JOB_DIR "/cmds/leitai/dzd/"

#define SRM JOB_DIR"boat.c"
#define DEATHS_ROOMO JOB_DIR"matou.c"
/*��ֻ�ļ�*/
#define GAME_TIME 1200
//600
/*��Ϸʱ��*/
#define NEXT_TIME 1200  

/*�غ�ʱ��*/
#define IN_TIME 420
//#define IN_TIME 120
//420
//300 7*60 420
/*�ӵ�һ���˿�ʼask����ʼ��ʱ��*/
#define EXP_LIMIT 3500
/*��߿��Ի�õ�EXP*/
#define FORBID_ML 0
/*�Ƿ�������ͬIP����Job
 *�˴��޶�Ϊ����ͬIP�μ�
 *��������� 0 ��ʾ��ֹ
 */

//Ϊ������� 
#define BOOK    "/clone/gift/book"      //��
#define MIC     "/clone/gift/danwan"    //ҩ
#define MON     "/clone/gift/money"     //Ǯ
#define JADE    "/d/zhiye/obj/othermaterial" //��
#define DAZAO   "/clone/gift/imbue"     //�������

inherit F_DBASE;

#include <ansi.h>
#include <mudlib.h>
//#include <job_mul.h>


nosave int debug = 0;   //����״̬
nosave int max_users = 40;//����������
nosave int min_users = 6;  //By lsxk ͬһip 2���ˣ�����3����������2*3=6
//nosave int min_users = 2;
//7
nosave int closed = 0;//�ر�״̬
nosave object author;//
nosave string* deads = ({"���϶�����","���ĺ��Ķ�����","������ܽ����","�䶾����",});
   ///add condition dead
nosave string game_name = "���ǵ�";
//int is_ghost() { return ghost; }

int one_live;
string stating;
mapping* user_list;
int start_time;
int over_time;
int total_exp;

int get_num(mixed me);
void demon_tell(int i,object me,string arg);
void job_over();

void create()
{
	seteuid(ROOT_UID);
	set("no_clean_up",1);
	set("channel_id",game_name+"���ƾ���");
	if(!user_list) user_list = ({});
}

string query_boat()
{
	return SRM;
}

int change_debug()
{
	if(debug==1){
		debug = 0;
	}
	else debug = 1;
	return debug;	
}

int query_exp()
{
	if(!sizeof(user_list)) return 0;
	return total_exp/sizeof(user_list);
}

int query_mode()
{
	return debug;
}

string query_name()
{
	return game_name;
}

void init_start()
{
	stating = "ready";
	//user_list = allocate_mapping(max_users);;	
	user_list = ({});
	start_time = time()+IN_TIME;
	total_exp = 0;
	one_live = 0;
	author = find_player("ciwei");
	remove_call_out("check");
	call_out("check",2);
}

void debug_msg(string arg)
{
	arg += "\n"NOR;
	if(debug && author) tell_object(author,arg);
}

string query_stat()
{
	if(undefinedp(stating) || stating=="waitby"  ) init_start();
	return stating;
}

int add_player(object me,int flag)
{
	int i;
	mapping db;
	
	if(sizeof(user_list)){
		int same_ip = 0;
		for(i=0;i<sizeof(user_list);i++){
			if(getuid(me)==user_list[i]["id"]) break;
			if(query_ip_number(me)==user_list[i]["ip"]) same_ip++;
			if(same_ip>FORBID_ML) break;
		}
		if(i!=sizeof(user_list)) return -1;
	}
	if(query_stat()=="ingame" || query_stat()=="overbusy") return -3;
	if(time() > start_time-5) return -3;//��ǰ����ask ��ΪaskҲ��������
	if(sizeof(user_list)>=max_users) return -2;
	if(closed) return 0;
	if(flag){
		db = (["id":           getuid(me),
			"object":      me,
			"asktime":     time(),
			"start_time":  start_time,
			"score":       0,
			"kar_bonus":   2*MAX(MAX(me->query_skill("zhizao",1),me->query_skill("duanzao",1)),me->query_kar()*10),
			"exp":         me->query("combat_exp"),
			"ready":       0,
			"over":        0,
			"alive":       1,
			"ip":          query_ip_number(me),
		]);///etc......
		debug_msg(sprintf("%O",db));
		if (!sizeof(user_list)){
                		user_list = ({ db });
                		CHANNEL_D->do_channel(this_object(),"rumor",HIY+me->name()+"������ȥ"+game_name+"̽�ա�");
                	}
        	else
                	user_list += ({ db });
                total_exp += db["exp"];
                me->delete_temp("job_xkd");
		me->set_temp("job_xkd/asked",1);
		me->apply_condition("job_busy",20);//��ֹȥask���job grin
	}
	return start_time;
}

int is_player(object me)
{
	if(add_player(me,0)==-1) return 1;
	return 0;
}

void get_item(object me)
{
	object* items = deep_inventory(me);
	if(!sizeof(items)) return;
        for(int i=0;i<sizeof(items);i++)
        	if( items[i]->query("dzd_obj") ) destruct(items[i]);
}

int clear_data(mapping db)
{
	if(!objectp(db["object"])) return 0;
	if(!db["ready"]){
		object ob;
		if(objectp(ob = find_player(db["id"]))){
			ob->delete_temp("job_xkd");
			get_item(ob);
			tell_object(ob,"������ȥ"+game_name+"��ʱ�䣡\n");
			ob->apply_condition("job_busy",1);//��ֹȥask���job grin
		}
		return 0;
	}
	return 1;
}

void player_ready(object me)
{
	int i;	
	i = get_num(me);
	if(undefinedp(user_list[i])) return;
	user_list[i]["ready"] = 1;
	//some msg
}

void give_item(object me)
{
	object item;
	string* items = ({
		JOB_DIR"npc/obj/baoyi",
		JOB_DIR"npc/obj/bishou",
		JOB_DIR"npc/obj/hssy",
		JOB_DIR"npc/obj/hulu",
		JOB_DIR"npc/obj/huqin",
		JOB_DIR"npc/obj/pimao",
		JOB_DIR"npc/obj/qxht",
		JOB_DIR"npc/obj/xsycw",
		JOB_DIR"npc/obj/yufeng",
		JOB_DIR"npc/obj/yuwang",
		JOB_DIR"npc/obj/ziweijian",
		JOB_DIR"npc/obj/qimen",
		JOB_DIR"npc/obj/zhujingbch",
		JOB_DIR"npc/obj/mujian",
		JOB_DIR"npc/obj/mianmo",
		JOB_DIR"npc/obj/dujing",
	});
	item = new(items[random(sizeof(items))]);
	
	if(clonep(item)) {
		item->set("dzd_obj",1);
		item->move(me);
		tell_object(me,HIY"���������������ĵ��߹�����������������ʲô������\n"NOR);
	}
}

void reward()
{
	int exp,pot,tb,shen,i;
	string str;
	string live_name = "ereesdfsdfd";
   object xyjob_letter;
	//object gift;	

	for(i =0;i<sizeof(user_list);i++){
		//int sss;
		int t;
		if(!user_list[i]["object"]) continue;
		str = HIW"��˷����˴��ѣ�";
		exp = 300+user_list[i]["score"]+random(user_list[i]["score"]/3);
		///���ٵȴ�5���� ��������500 exp
		//10m ����500 exp
		//	
		
											
		if(user_list[i]["score"]==0) exp += (  user_list[i]["over_time"]  -start_time)/6;//ûɱ���κ��� ��ʱ�佱��
		if(user_list[i]["dead"]) {exp = exp *2 ; exp = exp/3;str+="��Ȼ����ȫ����ˣ�";}
		if(!one_live) {exp = exp *2 ; exp = exp/3;str += "δ��̽��"+CHINESE_MUD_NAME+game_name+"����";}
		
		t = (user_list[i]["object"]->query("combat_exp") * 100 )/2000000;
		//t = t*100;
		if(t<=100) t = 100;
		if(t>500) t = 500;
		exp += t;
           if(one_live && user_list[i]["alive"] ) {
               exp = exp * 2;
               str+="��ʤ���飬";
               live_name = user_list[i]["object"]->query("name");
               if(!random(10)){
                   xyjob_letter=new("/clone/gift/xyjobletter");
                   xyjob_letter->move(user_list[i]["object"]);
                   sprintf(HIY"�����,�㷢�����Ͼ�Ȼ����һ�ֻ����ź�,�������̬����,��øϿ�����͵���������!\n"NOR);
                   log_file("job/xyjob", sprintf(HIY"%8s%s dzdjob ���ʤ��,��ÿ�����������ս���ߡ�"NOR,ctime(time())[4..19],user_list[i]["object"]->query("name")+"("+user_list[i]["object"]->query("id")+")" ));
               }
           else sprintf(HIM"����øղ����϶���һ������,������ȴ�Ҳ�����.....\n"NOR);
           }//��ʤ����limit����,��������50%�õ�����xyjob����. By lsxk@hsbbs 2007/7/17
				
		if(exp>EXP_LIMIT) exp = EXP_LIMIT-random(30);
		pot = exp /3;
		//��������
		shen = exp;
              tb = pot / 100;
		if(user_list[i]["object"]->query("family") &&  user_list[i]["object"]->query("family/family_name")=="�һ���") shen = 0;
		log_file("job/dazhidao",
		sprintf("%-8s%-8s ��ɴ��ǵ����� ��ý�����exp:%-4d pot:%-4d ��ǰexp:%d",user_list[i]["object"]->query("name"),user_list[i]["object"]->query("id"),exp,pot,user_list[i]["object"]->query("combat_exp") ),user_list[i]["object"]  );
		user_list[i]["object"]->add("combat_exp",exp);
		user_list[i]["object"]->add("potential",pot);
		user_list[i]["object"]->add("shen",shen);	
              user_list[i]["object"]->add("SJ_Credit", tb);	
              //by spiderii �Ӹ�����
 	       user_list[i]["object"]->delete_temp("other_kill");
	       user_list[i]["object"]->delete_temp("kill_other");

		if(user_list[i]["object"]->query("potential")> user_list[i]["object"]->query("max_pot")) user_list[i]["object"]->set("potential",user_list[i]["object"]->query("max_pot"));
		str +="�����Լ�����˿�����𣬶����书�����\n"NOR; 
		str += sprintf(HIC"���%s����%s�㾭�飬%s��Ǳ��",game_name,chinese_number(exp), chinese_number(pot) );
		if(shen) str += sprintf("��%s������Ľ�����\n"NOR,chinese_number(shen));
              if(tb) str += sprintf("��%s������ͨ���Ľ�����\n"NOR,chinese_number(tb));
		else str += "�Ľ�����\n"NOR;

		/*
		���ǵ����������������
        
		ÿ�����±�����Ҷ����ܶ����ã�����ս������ȫ����ģ�û���±�����ң�û�ж��⽱����
		ÿ��JOB��1/2������������½����е�һ�
		1��200 GOLD��
		2��500 EXP��	
		3��һ����1-4������������
		4��һ�����ܲ�ƪ��
		5��Τ��������
		
        
		���⣺��ڼ䣬ÿ�λ�ô��ǵ����������ͷ�ε�ID�����Ի��һ��߼�4��������/������(1/50)��
		���� 4 6 �������������
		*/
		/*if(user_list[i]["object"]->query_temp("quest/gift/mid-autumn/yuebing")
			&& random(2))//ֻ��һ�����н���
		{
			//���ʤ�����л�����һ�θ߼�����
			if(one_live && user_list[i]["alive"] && !user_list[i]["object"]->query("quest/gift/mid-autumn/winner") 
				&&!random(150))//��������²��ܻ��
			{
				level=3;
				if(!random(2)) level+=1;//4���Ŀ����Ժܴ�
				if(!random(20)) level+=1;//���ǰ���Ѿ�һ��random(50)�ˣ����ﻹ�еĻ�����Ŀ����в���
				gift = new(JADE);
				gift->set_level(level);
				user_list[i]["object"]->add("quest/gift/mid-autumn/winner",1);
				if(user_list[i]["object"]->query("registered")<3)
					log_file("quest/yuebing", sprintf("��VIP %s(%s)��ʤ���%d���±����%d������%s��ʤ�����ռ����\n", 
				                                 user_list[i]["object"]->name(1),
												 user_list[i]["object"]->query("id"),
												 user_list[i]["object"]->query("quest/gift/mid-autumn/yuebing"),
												 level,
												 gift->query("name")) );
				else
					log_file("quest/yuebing", sprintf("VIP %s(%s)��ʤ���%d���±����%d������%s��ʤ�����ռ����\n", 
				                                 user_list[i]["object"]->name(1),
												 user_list[i]["object"]->query("id"),
												 user_list[i]["object"]->query("quest/gift/mid-autumn/yuebing"),
												 level,
												 gift->query("name")) );
			}
			//������Ŀ��ܻ�������ֽ��������������������С������
			else if(user_list[i]["object"]->query("quest/gift/mid-autumn/special")>=2|| random(150))
			{
				sss=random(3);
				if(random(60))
				{
					switch(sss)
					{
					case 0: 
						gift = new (BOOK);
						break;
					case 1: 
						gift = new (MIC);
						if(!random(8)) gift->set("secret_obj",1);
						gift->set("bonus","combat_exp");
						break;
					case 2:         
						gift = new (MON);
						break;
					default:return;
					}
				}
				else
				{
					gift = new(JADE);
					gift->set_level(1+random(2));
				}
				gift->set("gift_target",user_list[i]["object"]->query("id"));
				gift->set("owner",user_list[i]["object"]->query("id"));
				if(user_list[i]["object"]->query("registered")<3)
					log_file("quest/yuebing", sprintf("��VIP %s(%s)���%d���±����%s�����б�����%d�Ρ�\n", 
				                                 user_list[i]["object"]->name(1),
												 user_list[i]["object"]->query("id"),
												 user_list[i]["object"]->query("quest/gift/mid-autumn/yuebing"),
												 gift->query("name"),
												 user_list[i]["object"]->query("quest/gift/mid-autumn/special")) );
				else
					log_file("quest/yuebing", sprintf("VIP %s(%s)���%d���±����%s�����б�����%d�Ρ�\n", 
				                                 user_list[i]["object"]->name(1),
												 user_list[i]["object"]->query("id"),
												 user_list[i]["object"]->query("quest/gift/mid-autumn/yuebing"),
												 gift->query("name"),
												 user_list[i]["object"]->query("quest/gift/mid-autumn/special")) );
			}
			else
			{
				level=1;
				sss = random(2);//���������������ܲ�ƪû�м���
				if(!random(5)) level+=1;
				if(!random(7)) level+=1;
				if(!random(9)) level+=1;//��ļ���1-4
				switch(sss)
				{
			    case 0:
					gift = new(DAZAO);
					break;
				case 1:
					gift = new(JADE);
					gift->set_level(level);
					break;
				default:return;              			
				}
				user_list[i]["object"]->add("quest/gift/mid-autumn/special",1);
				if(user_list[i]["object"]->query("registered")<3)
					log_file("quest/yuebing", sprintf(HIR"��VIP %s(%s)���%d���±���%d�λ�ñ���%s��\n"NOR, 
				                                 user_list[i]["object"]->name(1),
												 user_list[i]["object"]->query("id"),
												 user_list[i]["object"]->query("quest/gift/mid-autumn/yuebing"),
												 user_list[i]["object"]->query("quest/gift/mid-autumn/special"),
												 gift->query("name")) );
				else
					log_file("quest/yuebing", sprintf(HIR"VIP %s(%s)���%d���±���%d�λ�ñ���%s��\n"NOR, 
				                                 user_list[i]["object"]->name(1),
												 user_list[i]["object"]->query("id"),
												 user_list[i]["object"]->query("quest/gift/mid-autumn/yuebing"),
												 user_list[i]["object"]->query("quest/gift/mid-autumn/special"),
												 gift->query("name")) );
			}
			gift->set("gift_target",user_list[i]["object"]->query("id"));
			gift->set("owner",user_list[i]["object"]->query("id"));
			gift->move(user_list[i]["object"]);
			str += "�㻹����ػ��"+gift->query("name")+"�Ľ�����\n"NOR;
		}

		user_list[i]["object"]->delete_temp("quest/gift/mid-autumn/yuebing");//ȫ��ȥ����־
*/
		demon_tell(2+random(2),user_list[i]["object"],str );
	}
	str = "���ǵ�ð�ս�����";
	if(live_name != "ereesdfsdfd" && one_live) str += "����������ߣ�"+live_name+"��";
	else str += "��";
	CHANNEL_D->do_channel(this_object(),"rumor",HIY+str);
}

void quit_player(object me,int flag)
{
	int i;
			
	i = get_num(me);
	if(undefinedp(user_list[i])) return;
	if(user_list[i]["over"] == 1) return;
	if(user_list[i]["gift"] == 1){
		me->add_temp("apply/attack",-user_list[i]["kar_bonus"]);
		me->add_temp("apply/armor",-user_list[i]["kar_bonus"]);
	}	
	if(user_list[i]["gift"] == -1){
		me->add_temp("apply/dodge",user_list[i]["kar_bonus"]);
		me->add_temp("apply/parry",user_list[i]["kar_bonus"]);
	}	
	me->clear_conditions_by_type("poison");//clear poison
	me->clear_conditions_by_type("hurt");//clear poison
	me->clear_condition("killer");//clear killer
	me->remove_relay_listener("die");//ע��die������
	me->remove_all_killer();
	me->delete_temp("other_kill");
	me->delete_temp("kill_other");//delete flag sign
	me->delete_temp("dzd_quest");
	///dzd_quest some temp about obj room
	//me->apply_condition("job_busy",5+random(5));
	me->clear_condition("job_busy");
	me->set("job_name",game_name);
	if(flag) me->apply_condition("job_busy",10+random(10));	
	if(flag){
		object* obs;
		user_list[i]["dead"] = 1;
		user_list[i]["alive"] = 0;		
		obs = filter_array(all_inventory(me),(:$1->query("dzd_obj"):));
		if(sizeof(obs)){
			for(int j=0;j<sizeof(obs);j++)
				obs[j]->move( environment(me) );
			tell_room(environment(me),HIG"���ƺ�������"+me->name()+"����ʧ����ʲô������\n"NOR,({me}));
		}
		if (environment(me)) environment(me)->die(me);
		me->move(DEATHS_ROOMO);
		tell_room(environment(me),me->name()+"���˴ӵ������˳�����\n"NOR,({me}));
		me->set_temp("job_xkd/dead",1);
	       me->remove_all_killer();
	       me->delete_temp("other_kill");
	       me->delete_temp("kill_other");

		tell_object(me,"�㱻�����ˡ�\n");
	}
	//me->reincarnate();
        me->set("eff_jing", me->query("max_jing") + me->query_temp("apply/jing"));
        me->set("eff_qi", me->query("max_qi") + me->query_temp("apply/qi"));
        me->set("jingli", me->query("eff_jingli") + me->query_temp("apply/jingli"));
        me->set("jing", me->query("eff_jing"));
        me->set("qi", me->query("eff_qi"));
        
	get_item(me);//��ֹ�Ż�����
	if(!flag) me->add("job_time/"+game_name,1);
	//and gift 
	//this is a big quest -> about shenzhao-jing need close the wg shenzhao-jing quest
	user_list[i]["over"] = 1;
	user_list[i]["over_time"] = time();
	//if(flag) demon_tell(2+random(2),me,"����Ȼ����ί����ȴҲֻ��֪Ȥ������"+game_name+"��\n" );
	//else demon_tell(2+random(2),me,"��!"+game_name+"������һ�����������ȥ���硣\n" );
	
	//me->delete_temp("job_xkd"); delete this var in room
	//give msg
}
//HIM"ͻȻһ��������֣������������û�������ܿ����������ʱ���㷢���Ѿ�������һ��İ������ͷ��\n"NOR
void gogogo()
{
	int texp;
	//�����expƫ�͵�player ����kar_bonus �ٺ� �������ɣ�
	stating = "ingame";
	user_list = filter_array(user_list, (:clear_data:),);
	if(!sizeof(user_list)){
		job_over();
		return;
	}
	texp = total_exp/sizeof(user_list);
	for(int i=0;i<sizeof(user_list);i++){
		int rd;
		if(file_name(environment(user_list[i]["object"]))+".c"!=SRM){
			//�����û�����μӵĸ�..
			continue;
		}
		user_list[i]["object"]->register_relay_listener("die");//ע��die������ �����ֹ�����ʧ ������Log
		user_list[i]["object"]->set_temp("dzd_quest",([]) );
		debug_msg(sprintf("%O",user_list[i]["object"]->query_extra_listener() ) );
		rd = user_list[i]["exp"]>texp?10:90;
		if(random(100)<=rd){
			user_list[i]["gift"] = 1;
			user_list[i]["object"]->add_temp("apply/attack",user_list[i]["kar_bonus"]);
			user_list[i]["object"]->add_temp("apply/armor",user_list[i]["kar_bonus"]);
			debug_msg( sprintf("%-10s����attack armor �� %d",user_list[i]["object"]->name(),user_list[i]["kar_bonus"] ));
			demon_tell(2+random(3),user_list[i]["object"],HIW"�㷢�������������Ī�⣬�����Լ����书���г����������������棡\n"NOR);
			//�㷢�ִ��ǵ�����Ī�⣬�����Լ����书����ѹ�֣�����������߾��裡
		}
		else if(random(100)>rd)
		{
			user_list[i]["gift"] = -1;
			user_list[i]["object"]->add_temp("apply/dodge",-user_list[i]["kar_bonus"]);
			user_list[i]["object"]->add_temp("apply/parry",-user_list[i]["kar_bonus"]);
			debug_msg( sprintf("%-10s����dodge parry �� %d",user_list[i]["object"]->name(),user_list[i]["kar_bonus"] ));
			demon_tell(2+random(3),user_list[i]["object"],HIR"�㷢�������������Ī�⣬�����Լ����书����ѹ�֣�����������߾��裡\n"NOR);
		}
				
		//��߼ӵķ���
		
		//about no_pk
		if(user_list[i]["object"]->query("no_pk")){
			user_list[i]["object"]->set("dzd_no_pk",user_list[i]["object"]->query("no_pk"));
			user_list[i]["object"]->delete("no_pk");
		}
				
		give_item(user_list[i]["object"]);
		user_list[i]["object"]->set("job_name",game_name);
		tell_object(user_list[i]["object"],CYN"Զ������һ����죬��о������Ҵ����ҵ��𶯣���æ�˹��������ֿ���\n"NOR);		
		user_list[i]["object"]->set_temp("last_damage_from","�����������ķ�");
		user_list[i]["object"]->receive_damage("qi",random(300));
		user_list[i]["object"]->receive_wound("qi",random(200));
		user_list[i]["object"]->receive_damage("neili",random(1000));								
	}
	//give msg
}

void start_war()
{
	stating = "ingame";
	user_list = filter_array(user_list, (:clear_data:),);
	tell_room(SRM,"����վ��������ǰժ��ñ�ӣ��������Ǹ��������ӣ�ԭ����Ҳ���˴���\n");
	tell_room(SRM,"������������˵������������λȥ"+game_name+"Ѱ���������в�����ƣ��ղ����������ǵ��ϴ����������ǵ��ٹ�"+CHINESE_D->chinese_time(GAME_TIME)+"��Ҫ��û�ˡ�\n");
	tell_room(SRM,"�������ӽ���˵������ֻ��ת�۾�ҲҪ��û�������ı��·�ɡ�\n");
	tell_room(SRM,"��˵�����������Ѿ�����Ծ�뺣�С�\n");
	SRM->move_to_iland();
	over_time = time() + GAME_TIME;
	remove_call_out("check");
	call_out("check",2);
}

//dest all rooms
void job_over()
{
	mapping* lives;
	mixed *d;
	int i,fl;
	object f;
	
	stating = "overbusy";
	//dest
	user_list = filter_array(user_list, (:clear_data:),);
	lives = filter_array(user_list, (:$1["alive"]:) );
	if(sizeof(lives)) {
	for(i =0;i<sizeof(lives);i++)
		quit_player(lives[i]["object"],0);
	}
	
        d = get_dir(JOB_DIR,-1);
        for (i=0;i<sizeof(d);i++){
        	if (d[i][1] == -2) continue;
        	fl = strlen(d[i][0]);
        	if (d[i][1] <= 0
        	|| d[i][0][(fl-2)..(fl-1)] != ".c") continue;
    	        if (!(f = find_object(JOB_DIR+d[i][0]))) continue;
    	        destruct(f);
        }
        remove_call_out("init_start_re2");
        remove_call_out("init_start_re");
	call_out("init_start_re2",NEXT_TIME-30);
	call_out("init_start_re",NEXT_TIME);
}

void init_start_re2()
{
	CHANNEL_D->do_channel(this_object(),"rumor",HIY+"��˵"+game_name+"�������¸��������ˡ�");
}

void init_start_re()
{
	stating="waitby";
}

int sort_rank(mapping rank1, mapping rank2)
{
	reset_eval_cost(); // added by snowman@SJ
	return rank2["score"]-rank1["score"];
}

string query_score(object me,int list)
{
	int t;
	string msg = HIW+CHINESE_MUD_NAME+game_name;
	if(stating == "ready"){
		t = start_time - time();
		//CHINESE_D->chinese_time(t)
		if(t>0) msg += sprintf("������%s��Ҫ��ʽ��ʼ�ˡ�\n"NOR,CHINESE_D->chinese_time(t));
		else msg += "�����Ѿ���ʼ�ˡ�\n"NOR;
	}
	else if(stating == "ingame")
	{
		mapping* lives = filter_array(user_list, (:clear_data:) );
		mapping* deads = filter_array(lives, (:!$1["alive"]:) );
		//lives = filter_array(lives, (:clear_data:) );
		
		lives = filter_array(lives, (:$1["alive"]:) );
		t = over_time - time();
		if(!sizeof(lives) || t<=0) msg += "������û��\n"NOR;
		else msg += sprintf("��ʣ %s �ˣ����ٹ�%s���Ҫ��û�ˡ�\n"NOR,chinese_number(sizeof(lives)),  CHINESE_D->chinese_time(t) );
		if(list)
		{
			lives = sort_array(lives, (: sort_rank :));
			deads = sort_array(deads, (: sort_rank :));
			msg += "\n�����������������£�\n";
        		msg +="�q���������������������������������ש����������������ש����r\n";
        		msg +="��           "HIW"��    ��"NOR"             �� "HIW"�� �� �� �� ��"NOR" ��"HIW"״̬"NOR"��\n";
        		//msg +="��           "HIW"��    ��"NOR"             �� "HIW"�� �� �� �� ��"NOR" ��\n";
        		msg +="�ǩ��������������������������������贈���������������贈����\n";
        		if(sizeof(lives)) for(int i = 0;i<sizeof(lives);i++){
        			if(!lives[i]["object"]) continue;
        			msg += sprintf("��%|32s��%-16s��%|4s��\n",HIW+lives[i]["object"]->query("name")+"("+capitalize(lives[i]["id"])+")"NOR,HIW+chinese_number(lives[i]["score"])+NOR, (lives[i]["alive"]?HIG"�":HIR"����")+NOR  );
        		}
        		if(sizeof(deads)) for(int i = 0;i<sizeof(deads);i++){
        			if(!deads[i]["object"]) continue;
        			msg += sprintf("��%|32s��%-16s��%|4s��\n",HIW+deads[i]["object"]->query("name")+"("+capitalize(deads[i]["id"])+")"NOR,HIW+chinese_number(deads[i]["score"])+NOR, (deads[i]["alive"]?HIG"�":HIR"����")+NOR  );
        		}
        		msg +="�t���������������������������������ߩ����������������ߩ����s\n";
		}
	}
	else if(stating == "overbusy") msg +="�Ѿ�������\n"NOR;
	else if(stating == "waitby") msg +="����׼�����¿�ʼ��\n"NOR;
	return msg;
}

void check()
{
	//���������׶�
	//start init call�Ժ�ʼ�ĵȴ�ʱ��	
	remove_call_out("check");
		
	if(stating == "ready"){
		if(time() < start_time){
			call_out("check",4);
			return;
		}
		user_list = filter_array(user_list, (:clear_data:),);
		if(sizeof(user_list)<min_users) {
			CHANNEL_D->do_channel(this_object(),"rumor",HIY+"�����������㣬��ʱȡ����ȥ���ǵ��ļƻ���");						
			job_over();
			return;
		}
		SRM->run_sea();
		call_out("gogogo",10+random(10));
		call_out("start_war",23+random(5));
		return;
	}
		
	if(stating == "ingame")
	{
		mapping* lives = filter_array(user_list, (:clear_data:) );
		lives = filter_array(lives, (:$1["alive"]:) );
		//lives = filter_array(lives, (:clear_data:) );		
		if(time() < over_time && sizeof(lives)>1 ){
			call_out("check",4);
			return;
		}
		one_live = sizeof(lives)==1;
		job_over();
		reward();
		return;
	}	
}

void demon_tell(int i,object me,string arg)
{
	call_out("demon_tell2",i,me,arg);
}
void demon_tell2(object me,string arg)
{
	tell_object(me,arg);
}

int relay_listener(object me,string type)
{
	///�������� �˳���Ϸ������
	mixed hehe;
	object mul;
	int flag = 1;
	string str;
	int i;
	int bonus;
	if(type=="die"){
		//����ԭ���б���б��� score �ӱ�		
		//�������ݴ��ʱ��
		if(stringp(hehe= me->query_temp("last_damage_from")) && member_array(hehe,deads)!=-1) flag = 2;
		//���¶����˲��ֽ��� ^_^
		//����������						
		if(objectp(mul= me->query_temp("faint_by")) && userp(mul) ) {
			i = get_num(mul);
			bonus = 300*(me->query("combat_exp")/1000);
			bonus = bonus/(mul->query("combat_exp")/1000);			
			if(i!=max_users+10 && !undefinedp(user_list[i])) {
				debug_msg(sprintf("%s �õ�%d score",mul->query("name"), bonus*flag ));
				user_list[i]["score"] += bonus*flag;
				flag = 1;
			}
		}
		//����������
		if(objectp(hehe= me->query_temp("last_damage_from"))  && mul!=(object)hehe && userp(hehe) ) {
			i = get_num(hehe);
			bonus = 300*(me->query("combat_exp")/1000);
			bonus = bonus/(hehe->query("combat_exp")/1000);
			//
			if(i!=max_users+10 && !undefinedp(user_list[i])) {
				debug_msg(sprintf("%s �õ�%d score",hehe->query("name"), bonus*flag ));
				user_list[i]["score"] += bonus*flag;
				flag = 1;
			}
		}
		/*		
		
		if(objectp(hehe= me->query_temp("last_damage_from"))  && userp(hehe) && (i = get_num(hehe))!=max_users+10 )
			if(!undefinedp(user_list[i])) {user_list[i]["score"] += 150*flag;flag = 1;}
		*/				
		if(stringp(hehe)){
			str = me->query("name")+hehe;
			if(hehe[<2..<1] != "��") str += "���ˡ�";
		}
		if(objectp(hehe)) str = sprintf("%s��%s���%s�ˡ�",me->query("name"),hehe->name(),game_name);
		if(objectp(hehe) && objectp(mul) && (object)hehe!=mul ) str= sprintf("%s��%s��%s�������%s�ˡ�",me->query("name"),hehe->name(),mul->name(),game_name);
		CHANNEL_D->do_channel(this_object(),"rumor",str);
		quit_player(me,1);
		//me->remove_relay_listener(type);
		// remove this listener
	}
	return 1;
}

int get_num(mixed me)
{
	int i;
	string id;
	if(!sizeof(user_list)) return max_users+10;
	
	if(objectp(me)) id = getuid(me);
	else id = (string)me;
	
	for(i=0;i<sizeof(user_list);i++) if(id==user_list[i]["id"]) break;
		
	if(i==sizeof(user_list)) return max_users+10;
	return i;
}
