// song.c ��Զ��
// ���ļ�Ϊbonus�������ļ�
// bonus/�䵱 bonus/ѩɽ ���ֱ��淽ʽ���治ͬJob�µ�bonus
// By Spiderii@ty ��Ҫjob npc.�޷�ɱ��!
// By Spiderii@ty ����yttlg quest
// By lsxk@hsbbs 2008/1/11  ͳһ�������㷨��

inherit NPC;
inherit F_MASTER;

#include <jobround.h>
#include <job_mul.h>
#include <ansi.h>
#include <get_place.h>
string ask_me();
string ask_me1();
string ask_me2();
string ask_me3();
string ask_me4();
string ask_me5();
string ask_me6();

int check(object ob);

void create()
{
       set_name("��Զ��", ({ "song yuanqiao", "song" }));
       set("nickname", "�䵱����");
       set("long",
               "������������Ĵ���ӡ��䵱����֮�׵���Զ�š�\n"
               "��һ���ɸɾ����Ļ�ɫ���ۡ�\n"
               "���������ʮ������ݳ���������⡣�񵭳�ͣ���Ĭ���ԡ�\n");
       set("gender", "����");
       set("age", 61);
       set("attitude", "peaceful");
       set("shen", 10000);
       set("str", 29);
       set("int", 27);
       set("con", 26);
       set("dex", 26);
       set("no_get","��Զ�Ŷ������̫���ˡ�");
       set("no_bark",1);
       set("job_npc", 1);

       set("max_qi", 1500);
       set("max_jing", 1000);
       set("neili", 2000);
       set("max_neili", 2000);
       set("jiali", 50);
       set("combat_exp", 1000000);
       set_skill("blade", 130);
       set_skill("cuff", 130);
       set_skill("force", 130);
       set_skill("yinyun-ziqi", 130);
       set_skill("dodge", 130);
       set_skill("wudang-quan", 130);
       set_skill("tiyunzong", 130);
       set_skill("taoism", 180);
       set_skill("strike", 180);
       set_skill("zhenshan-mianzhang", 180);
       set_skill("parry", 130);
       set_skill("literate", 100);
       set_skill("xuanxu-daofa", 140);
       set_skill("sword", 180);
       set_skill("taiji-jian", 180);
       map_skill("sword", "taiji-jian");
       set_skill("wudang-quan", 140);
       map_skill("force", "yinyun-ziqi");
       map_skill("dodge", "tiyunzong");
       map_skill("strike", "zhenshan-mianzhang");
       map_skill("parry", "zhenshan-mianzhang");
       prepare_skill("strike", "zhenshan-mianzhang");
       create_family("�䵱��", 2, "����");

       set("inquiry", ([
                "�ؼ�" : (: ask_me :),
                "��Ҫ" : (: ask_me1 :),
                "����" : (: ask_me2 :),
                 "job" : (: ask_me2 :),
                "Ѳɽ" : (: ask_me2 :),
              "fangqi" : (: ask_me3 :),
                "����" : (: ask_me3 :),
             "abandon" : (: ask_me3 :),
                "����" : (: ask_me4 :),
                "����" : (: ask_me4 :),
                "����" : (: ask_me4 :),
            "gongxian" : (: ask_me4 :),
             "gonglao" : (: ask_me4 :),
               "cishu" : (: ask_me4 :),
               "�ص�"  : (: ask_me5 :),
               "���"  : (: ask_me6 :),
               "finish"  : (: ask_me6 :),
       ]));

       set("book_count1", 1);
       set("book_count2", 1);
       setup();

       carry_object("/d/wudang/obj/white-robe")->wear();

}



int ask_me6()
{
        int e,shen,count,j,i,time,gold,gold2;
        mapping fam;
        object ob;
        ob = this_player();

        if (!ob) return; 
 
        fam = ob->query("family");
        count = ob->query("job_time/�䵱",1);

        j = ob->query("bonus/�䵱");
        e = 110*j + random(100);         //modify by campsun
		
		if (e <= 100) e=100+random(25);
                if( e>=500) e=400+random(20);
			
        if(ob->query_temp("wd/wd_job_lost2")) {
            command("faint "+ob->query("id"));
            command("say "+ob->name()+"�������ɵ���������"+ob->query_temp("wd/wd_job_lost2_man")+"�Ѿ�������Ƕ����������ˣ�");
            ob->delete_temp("wd/wd_job");
            ob->delete_temp("wd/wd_job_place");
            ob->delete_temp("wd/wd_job_lost2");
            ob->delete_temp("wd/wd_job_lost2_man");
            ob->add("bonus/�䵱",-3);
            ob->apply_condition("job_busy", 3);
            return 1;
        }
        if(ob->query_temp("wd/wd_job_lost") && !ob->query_temp("wd/wd_jobok") ) {
            command("sigh "+ob->query("id"));
            command("say "+ob->name()+"����ô��ģ���Ȼ���Ƕ��������ˣ�");
            ob->delete_temp("wd/wd_job");
            ob->delete_temp("wd/wd_job_place");
            ob->delete_temp("wd/wd_job_lost");
            ob->add("bonus/�䵱",-3);
            ob->apply_condition("job_busy", 3);
            return 1;
        }
       
        if(ob->query_temp("wd/wd_jobok") ){        	
            command("thumb "+ob->query("id"));
            command("say �ܺã�ף���������������ȥ��Ϣ��Ϣ�ɣ�");            
            count += 1;
            ob->set("job_name","�䵱����");
            if( ob->query("family") && ob->query("family/family_name")!="�һ���")
                shen = 1;
            else
                shen = 0;

            if(ob->query("bonus/�䵱") < 1)
                TASKREWARD_D->get_reward(ob,"�䵱",shen,0,0,2+random(2),0,0,0,"��Զ��");
            else
                TASKREWARD_D->get_reward(ob,"�䵱",shen,0,0,ob->query("bonus/�䵱")+ random(3),0,0,0,"��Զ��");

            ob->delete_temp("wd/wd_job");
            ob->delete_temp("wd/wd_job_place");
            ob->delete_temp("wd/wd_jobok");
    
            i = 40 - ob->query_condition("wd_job");
            if (i >= 18)
                ob->apply_condition("job_busy", 1);
            else
                ob->apply_condition("job_busy", (18-i)/3);
            ob->apply_condition("wd_job", e/100);
            
       // yttlg quest.
        // ����ֵ���� 1M �䵱����������� 2000
	// ��Ե��������� 25 24Сʱһ�� ����������ơ�
       time = time() - ob->query("quest/yttlg/time");                                           
	if (random(ob->query("job_time/�䵱")) >2000 
              && time > 86400
              && ob->query("combat_exp")>1000000
		          && random(ob->query("kar")) > 25
		          && !ob->query_temp("quest/yttlg/story")
              && !ob->query("quest/yttlg/pass")
              && (ob->query("quest/yttlg/fail") <= 3 || ob->query("registered")==3 )
	          	&& ob->query("family/family_name")=="�䵱��"
		 ) 
	      {      
		ob->set_temp("quest/yttlg/story",1);
              ob->set("quest/yttlg/time", time());
	  log_file("quest/yttlg", sprintf(HIR"%s(%s) ������������������Դ��%d�����飺%d��\n"NOR, ob->name(1),ob->query("id"), ob->query("kar"),ob->query("combat_exp")) );

		command(HIW"say "+ob->query("name")+",������ʦ����ʮ�ٳ�֮��,�������������߸�ʦ�ֵܼ�����ʦ�����١�\n"NOR);
		command(HIW"say ֻ������ʦ�������ǰ����ȥ�Ϸ�����һ�޵�,�ٳٲ����������㲻��ȥɽ����ӭӭ,ĪҪ����ʱ����\n"NOR);
	      }   
        return 1;
     }

       else {

            command("? "+ob->query("id"));
            command("kick "+ob->query("id"));
            command("say "+ob->name()+"����ô��ģ�����û��,�ҿ����ǵ������ˣ�");  
         return 1;}


        return 1;

}

  

void kill_ob(object me)
{
       set("chat_chance_combat", 20);
       set("chat_msg_combat", ({
               (: perform_action, "strike.bingdi" :),
               (: perform_action, "dodge.zong" :),
        }));
        ::kill_ob(me);
}

int accept_fight(object me)
{
        if((int)me->query("shen") < 1) {
           command("say ϰ��֮��Ӧ־�ڳ�����ƣ�"+RANK_D->query_respect(me)+"Ŀ¶��������Υ��ѧ֮����");
           return 0;
        }
        ::fight_ob(me);
         return 1;
}

void attempt_apprentice(object ob)
{
       if ((int)ob->query("shen") < 10000) {
               command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
               command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                       "�Ƿ����ò�����");
               return;
       }
       command("say �ðɣ�ƶ�����������ˡ�");
       command("recruit " + ob->query("id"));
}

string ask_me()
{
       mapping fam;
       object ob;
       if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
               return RANK_D->query_respect(this_player()) +
               "�뱾��������������֪�˻��Ӻ�̸��";
       if(query("book_count2") < 1)
         return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";
       add("book_count2",-1);
       ob = new(BOOK_D("force_book"));
       ob->move(this_player());
       return "�ðɣ��Ȿ��̫��ʮ��ʽ�����û�ȥ�ú����С�";
}

string ask_me1()
{
        mapping fam;
        object ob,song;
        song = this_object();
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
                return RANK_D->query_respect(this_player()) +
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("book_count1") < 1)
           return "�������ˣ�������Ҫ�Ѿ����ڴ˴��ˡ�";
        add("book_count1",-1);
        ob = new(BOOK_D("blade_book"));
        ob->move(this_player());
        return "�Ȿ���н����ĵ���Ҫ�죬���ȥ�ú��о�һ�¡�";
}

string ask_me2()
{
        object me, ob, *living, target;
        string str,str2;
        string str_temp;
        object room, oroom, lastroom;
        int i, j, k, a, b,t;
        string * exits,*dirs;
        string far;

        me=this_player();
        str2 = me->query_temp("wd/wd_job_place");
        str_temp = "";

        if (me->query_temp("wd/wd_job") && !me->query_temp("wd/wd_job_place"))
              return "���������Բ��𣬵ص�������������������ɡ�";

        if (me->query("combat_exp") < 100000 )
              return "��λ" + RANK_D->query_respect(me) + "�书δ�ɣ�����ȥ����Ĺ����ɣ�";

		if(me->query_temp("quest/busy")) //added by tangfeng ��quest��ͻ
			return "����������û�и���������㻹���ȴ����������������˵�ɡ�";

 
        if(!wizardp(me)){
        if (me->query("menggu"))
           return "�ߣ����������ɹţ�������ʲô��";

        if ( me->query_condition("killer"))
                return "�������ǹٸ�׽�õ�Ҫ������������䵱���飿";

        if (me->query_temp("wd/wd_job"))
              return "�Ҳ��Ǹ��������������ڵ��ҡ���Ϳ�ȥ�ɣ�";

        if (me->query("job_name") =="�䵱����")
              return "��������䵱�������񣬻�����ȥ��Ϣһ��ɡ�";

        if (me->query("shen") < 10000 && !wizardp(me) )
              return RANK_D->query_respect(me) + "�����������������޷������������������";

        if ( me->query_condition("job_busy")){
              if (me->query("job_name")=="�䵱����")
                  return "������ʱ��û�й�������ȥ����";
                if( me->query("job_name"))
                  return "�������"+me->query("job_name")+"���񣬻�������Ϣһ��ɡ�";
                return "����æ�ű�������ء�";
        }

        if (me->query_condition("wd_job"))
             return "������ʱû���ʺ���Ĺ�����";
  
	}

	ob=new(__DIR__"robber");
	ob->move(environment(this_object()));
		
	living = livings();
	for (i=0;i<sizeof(living);i++){
		j = random(sizeof(living));
		if (j <= 1 || j == sizeof(living)-1) continue;
		if( check(living[j]) ){
			target = living[j];
			room = environment(target);
			if( !mapp(room->query("exits")) || sizeof(room->query("exits"))<1 ) continue;

			if( get_place(base_name(room))!="" ) {
				oroom = room;
				if ( random(10)<3 && target->query("race")=="����" ) {
					j = 0;
					break;
				}

				lastroom = room;
				j = 1+random(4);//�ĵú���Щ:)
				for(k=0;k<j;k++) {
					exits = values(room->query("exits"));
					dirs = keys(room->query("exits"));
					b = sizeof(exits);
					t =0;
					while( (a=random(b))>=0 && b>1 && t<10 ) {
						t++;
						if(!room->valid_leave(ob, dirs[a])) continue;
						if (b==2)
							if ((exits[0]==base_name(lastroom) && exits[1]==base_name(oroom))
							 || (exits[1]==base_name(lastroom) && exits[0]==base_name(oroom)))
								break;
						if (exits[a]==base_name(lastroom) || exits[a]==base_name(oroom)) continue;
						break;
					}
					//write(sprintf("%d\n",t));
					lastroom = room;
					if( !(room = find_object(exits[a])) )
						if( !(room = load_object(exits[a])) )
							break;
				}
				if(k<j) continue;
				break;
			}
		}
	}

        if( !target || !room )
                return "��ʱû��������Ҫ�������һ��������ɡ�";

        me->set_temp("wd/wd_job",1);
        me->set_temp("wd/wd_job_place", get_place(base_name(oroom))+oroom->query("short"));
        me->apply_condition("wd_job",25+random(10));
        me->apply_condition("job_busy",25+random(10));
        command("nod "+me->query("id"));
        
		if (me->query("bonus/�䵱") >= WD_JOB_ROUND || !me->query("bonus/�䵱") || me->query("bonus/�䵱")<1 )
		{
			if (me->query("bonus/�䵱") == WD_JOB_ROUND)
				me->set("bonus/�䵱",4);
			else
				me->set("bonus/�䵱",1);
		}
		else
			me->add("bonus/�䵱",1);         

        ob->set_temp("target", me->query("id") );
        ob->setparty(me->query("bonus/�䵱"),me->query("max_pot")-100,me->query("combat_exp"));
        ob->move(room); 
        
        log_file("job/wd_job",sprintf("%s(%s)��ʼ��wd job,Ŀǰʵս���飺%d\n", me->name(),me->query("id"),me->query("combat_exp")),me);
        str = strip(me->query_temp("wd/wd_job_place"));
        
        if(wizardp(me) && me->query("env/test")){
		tell_object(me,"Ŀ��Npc�� "+base_name(oroom)+" �Ƶ�-> "+base_name(room)+"    "+room->query("short")+"\n");
           tell_object(me,"Round:"+me->query("bonus/�䵱")+" !\n");
       }
        if (j)
        	far = HIY+"��Χ��Բ"+CHINESE_D->chinese_number(j)+"��֮��"+GRN;
        else
        	far = "";
        if (strlen(str)<=1) {
                tell_object(me, GRN"��Զ������Ķ�������˵������˵"+ob->query("title")+HIC+ob->query("name")+GRN"����\n"
                        +HIY+ CHINESE_D->font(str)
                        + GRN + far +"���ң�������ȥ����Ѳ��һȦ��\n");
                
        } else
                tell_object(me, GRN"��Զ������Ķ�������˵������˵"+ob->query("title")+GRN+ob->query("name")+"����"+ me->query_temp("wd/wd_job_place") +GRN + far + "���ң�������ȥ����Ѳ��һȦ��\n");
        
        if (ob->query("family/family_name")=="�䵱��")
        	str_temp+=GRN"��Զ������Ķ�������˵����"+RANK_D->query_self(this_object())+"��׷�鵽���������䵱������Ϊ�ó�"HIC+to_chinese(ob->query("f_w_skill"))+GRN"�Ĺ���\n"+
        	RANK_D->query_respect(ob)+"���ܽ�����ɱ������Ϊ������ȥһ����Ҳ��Ϊ"+RANK_D->query_self(this_object())+"�ָ��������Ե��м�������\n";
        else {
                str_temp+=GRN"��Զ������Ķ�������˵���������ɵ�������������������"HIY+ob->query("family/family_name")+GRN"��";
        	if (random(2)==0)
        		str_temp+="��ͽ��";
        	else
        		str_temp+="���֣�";
        	str_temp+= "��Ϊ�ó�"HIC+to_chinese(ob->query("f_w_skill"))+GRN"�Ĺ���\n";
        }
        
       	switch ((int)me->query("bonus/�䵱"))
       	{
       		case 6..7:
       			str_temp+=GRN"��Զ������Ķ�������˵�������˵��书" + HIC + "��Ϊ�˵�" + GRN + "����ɵ�С�ĶԸ�Ŷ��\n"NOR;
       		break;
       		case 8..9:
       			str_temp+=GRN"��Զ������Ķ�������˵�������˵��书" + HIC + "��������" + GRN + "����ɵ�С��Ӧ����\n"NOR;
       		break;
       		case 10:
       			str_temp+=GRN"��Զ������Ķ�������˵�������˵��书" + HIW + "���뻯��" + GRN + "���򲻹��ɲ�Ҫ���ܡ�\n"NOR;
       		
       	}	
       		
       	tell_object(me, str_temp);	
       		
  		tell_room( environment(this_object()), this_object()->name() + "��" + me->name() + "����С����˵��Щ����\n", ({ me, this_object() }) );              
                        
        return "���ȥ��أ�һ��С�İ���";
}

string ask_me3()
{
        object ob = this_player();

        if(ob->query_temp("wd/wd_job")){
                ob->delete_temp("wd/wd_job");
                ob->delete_temp("wd/wd_job_place");
                
                if (ob->query("bonus/�䵱")<=5)
                {
                	ob->apply_condition("job_busy", 8);
                	ob->set("bonus/�䵱",0); 
                	return ob->name()+"����̫����ʧ���ˣ���Ȼ��ô���ɲ��ã������°ɣ�";
                }
                else if (ob->query("bonus/�䵱")>5)
                {
                	ob->apply_condition("job_busy", 4); 
                	ob->add("bonus/�䵱",-3);
                	return ob->name()+"���������ȷʵ�Ƚ�����ɣ��´θ���򵥵ģ������°ɣ�";                	
                }
        }
        return ob->name()+"������û��������������Ϲ����ʲôѽ��";
}

string ask_me4()
{
        object ob;
        ob = this_player();
        if(!ob->query("job_time/�䵱")){
            return "�Բ���"+ob->name()+"�������û������������������أ����͸ɰɣ�";
        }
        return ""+ob->name()+"�����Ѿ��ɹ��ز�����"+CHINESE_D->chinese_number((int)ob->query("job_time/�䵱"))+"��������";
}
string ask_me5()
{
	object me;
	string str;
	me = this_player();
	str = strip(me->query_temp("wd/wd_job_place"));
	
	
	if (!me->query_temp("wd/wd_job"))
              return "�㶼û������������ô֪����Ҫɱ�Ķ���������ȥ���أ�";
        if (strlen(str)<=1) {
                tell_object(me, GRN"��Զ������Ķ�������˵������Ҫɱ�Ķ�������\n"
                        + CHINESE_D->font(str)
                        + GRN + "���������أ��㻹������ȥѲ��һȦ��\n");
                
        } else
                tell_object(me, GRN"��Զ������Ķ�������˵������Ҫɱ�Ķ�������"+ me->query_temp("wd/wd_job_place") + GRN +"���������أ��㻹������ȥѲ��һȦ��\n");
        return "һ·С�İ���";

	
}
void destroying(object obj)
{
        if (!obj) return;
        if (userp(obj)) command("drop "+obj->parse_command_id_list()[0]);
          else destruct(obj);
}

string *no_kill_list = ({
         "mu ren", "jin ren", "yin ren", "zhong shentong", "zhu cong", "shi ren", "huo du","he shiwo"
});

int check(object ob)
{
        object room;
        string room_name;

        if(!objectp(ob)
         || !ob->query("startroom")      // add by Yuj@SJ to void job NPC
         || ob->query("env/invisibility")
         || ob->query("no_quest")
         || member_array(ob->query("id"), no_kill_list) != -1
         || userp(ob)
         || ob->query("attitude")=="aggressive"
         || ob->query("have_master")
         || !objectp(room=environment(ob))
         || room->query("no_fight")
         || room->query("quest")
         || room->query("outdoors") == "���ش��"
         || room->query("short") == "���º�ȭ��"
         || room->query("short") == "��ɮ��"
         || strsrch(room_name = file_name(room),"/d/") != 0                    //modified by campsun 2004.2.4 Ϊ�˺�bx code����
         || strsrch(room_name, "/d/wizard/") == 0
         || strsrch(room_name, "/d/wuguan/") == 0
         || strsrch(room_name, "/d/death/") == 0
         || strsrch(room_name, "/d/mingjiao/lsd/") == 0
         || strsrch(room_name, "/d/mingjiao/bhd/") == 0
         || strsrch(room_name, "/d/shaolin/fumoquan") == 0
            || strsrch(room_name, "/d/wudang/houshan/") == 0
   || strsrch(room_name, "/d/quanzhen") == 0
   || strsrch(room_name, "/d/menggu/") == 0
   || strsrch(room_name, "/d/xiakedao/") == 0
   || strsrch(room_name, "/d/luoyang/") == 0    
   || strsrch(room_name, "/d/beijing/") == 0
   || strsrch(room_name, "/d/mr/mtl") == 0
         || strsrch(room_name, "/d/baituo/") == 0)
         return 0;
        return 1;
}
void die()
{
	object ob;
	if (!query_temp("living"))
	{
		ob = new("/kungfu/class/wudang/song");
		ob->move("/d/wudang/sanqing");
	}
	::die();
}
