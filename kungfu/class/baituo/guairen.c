// guairen.c ŷ����
// by snowman 12/02/98
// Modified by snowman@SJ 2000.

#include <ansi.h>
inherit NPC;
void create()
{
       set_name("����", ({ "guai ren", "ren", "man" }) );
       set("gender", "����" );
       set("shen_type", -1);
       set("age", 70);
       set("per", 20);
       set("long","һλ��ͷ֧�ڵ��ϣ�˫�Ų�£��������յĹ��ˡ�
����ȥ�����ġ��������߱���Ŀ������ѩ�׶�
�룬���������������������˵��ߴ�������
�ֻ�������������\n" );
       set_temp("hide_level", 45+random(6));	
       set("inquiry", ([
                "ŷ����" : "ŷ���桢ŷ���棬������������ͦ��ġ�����\n",
                "���߹�" : "���߹���������Ҳ�졣\n",
                "��󡹦" : "��󡡢��󡡢��󡡣����\n",
                "name" : "�ҡ�����˭����֪������˭�ͺ�����\n",
       ]));
       setup();
       carry_object(BINGQI_D("gangzhang"));
       carry_object(ARMOR_D("cloth"))->wear();
       add_money("silver", 10);
}

void kill_ob(object me)
{     
      me->remove_all_enemy();
      this_object()->remove_all_enemy();
}

void do_back(object me)
{     
      if(!me || environment(me) != environment(this_object())) return;
      message_vision(HIY"\n ���к�Ȼ������ণ���ͷ����ڰ�շ��Ӷ�����\n\n"NOR,me);
      call_out("do_leave", 5, me);             
}

void init()
{
        object *ob, me = this_player();
        int i;
        ::init();     
        
        //if( wizardp(me) || SECURITY_D->get_status(me) == "(immortal)" ) return; 
                  
        if( base_name(environment(this_object()))!="/d/jiaxing/river1" ) return;
                
        if( me->query_temp("oyf/ok") ){
              command("look " + me->query("id"));
              command("hehe");
              command("say ��Խ�Ƕ������ܣ����ϵĶ�Խ�Ƿ����ÿ졣");
              call_out("do_wait", 360, me);
        }   
        else if(sizeof(ob = all_inventory(environment(this_object()))) > 2){
        	//command("say inv="+sizeof(ob));
                for(i=0; i<sizeof(ob); i++) {
                    if( ob[i]==this_object() || ob[i]==me ) continue;
                    if(wizardp(ob[i]) || SECURITY_D->get_status(ob[i]) == "(immortal)")
        	       log_file("quest/hamagong", sprintf("��%8s%-10s�Ƿ�����ŷ���崦ʱ��%8s%-10s���ֳ���\n", 
        	       	me->name(1),"("+me->query("id")+")", ob[i]->name(1), "("+ob[i]->query("id")+")" ), me); 
        	} 
        } 	
        add_action("do_kneel","kneel");
        add_action("do_kneel","gui");
        add_action("do_turn","turn");
        add_action("do_jiao","jiao");
        
}

int do_kneel(string arg)
{
     	object me, oyf;
     	int number;
     	me = this_player();
     	oyf = this_object();  
            
     	number = me->query_temp("oyf/kneel");
     
      	if( !me->query_temp("oyf/ok") || !arg) return 0;

      	if(arg == "guai ren" || arg == "ren" || arg == "man") { 
           	if(!number) {   
                	message_vision(CYN"\n$n��Ȼ�������飬��$N˫ϥ�򵹣��е��������Ϲ���������������\n"NOR,oyf,me);  
                	me->set_temp("oyf/kneel", 1);   
                	if ((string)me->query("gender") == "Ů��") { 
                      		command("hmm " + me->query("id"));
                      		command("say �ðɣ��ҾͰ�������ⶾ��");
                      		message_vision("ֻ��$N������������ס$n�ֱ����ü��£��Ѿ���$n�еı������붾���ˡ�\n",oyf,me);
                      		me->clear_condition("bing_poison");
                      		call_out("do_back", 2, me);
                      	}
                	else 	message_vision("����ҡ��ҡͷ�������Ѿȣ��Ѿȣ���\n",me);
                }
           	else if (number == 1) {
                	message_vision(CYN"\n$n���ڵ��϶�$N�������㱾������󣬶��ܾ��ҡ���\n"NOR,oyf,me);  
                	message_vision("$N���Ǹ��ˣ�΢΢һЦ������������֪�ұ��´󣿡�\n",oyf); 
                	me->set_temp("oyf/kneel", 2);
                }
           	else {
                	message_vision(CYN"\n$næ��$N�������㵹ת�����ӻ��ܵ�����죬������û�ڶ����������㡣��\n"NOR,oyf,me);  
                	message_vision("$N������Ц���������ң��е������ã��ã����޵�(turn)���������������ơ���\n",oyf);
                }
        }
      	return 1;
      
}

int do_turn()
{
      	object me, oyf;
      	me = this_player();
      	oyf = this_object();              
      	if( me->query_temp("oyf/kneel") != 2) return 0;
      
      	tell_object(me, HIC "�����벻���Լ�ֱ������������ȷ���Ʋ������������Ը˳����ֻ���Լ������ˡ�\n" NOR );      
      	message_vision("\n$n���µ�ת���ӣ���ͷ���ڵ��£����������ε����Գ�ס����$N��������ù�������Ⱦ��ҡ���\n\n", oyf, me);
      
        if(me->query("age") >= 14 && me->query("age") <= 100) call_out("oyf_ask", 4, me);  
      	else call_out("oyf_cure1", 4, me, oyf);   
      	return 1; 
}

void oyf_ask(object me)
{   
	if(!me || environment(me) != environment(this_object()) ) return;
        message_vision("$Nб������$n������ϲɫ���Եü������⡣\n",this_object(),me);
        command("say �ã����㲻�ѣ�������ô�Ӧ��һ���¡�");
        command("say ��Ҫ����Ϊ�����������ҹ�����Ҫ��(jiao)�ְ֡�");
        me->set_temp("oyf/say", 1);
        call_out("do_wait", 320, me);    
}

void do_wait(object me)
{
        if(!me || environment(me) != environment(this_object()) ) return;
        if(!me->query_temp("oyf_son")){
               command("hmm");
               do_back(me); 
        }
}

int do_jiao(string arg)
{      
       	object me, oyf;
       	me = this_player();
       	oyf = this_object();    
       	if( me->query_temp("oyf/kneel") != 2 || !arg
       	|| !me->query_temp("oyf/say") ) return 0;
  
       	if(me->query_temp("oyf/say") >=4 ){   
           	do_wait(me);   
           	return 1;
       	} 
       	me->add_temp("oyf/say", 1); 
        
       	if(arg == "�ְ�"){ 
             	message_vision(HIC"$N����һ����������¶��һ�����ְ֣��ְ֡���ڶ�����\n"NOR, me );
             	remove_call_out("do_wait");
             	me->delete_temp("oyf/say");
             	call_out("do_cure", 4, me);             
       	}
       	else {
             	command("hmm");
             	command("say ��аְ֡�");
             	me->add_temp("oyf/say", 1);
       	}
       	return 1;
}

void do_cure(object me)
{
      	object oyf = this_object();   
      
      	if(!me || environment(me) != environment(this_object())) return;
             
      	command("haha");
      	command("say �Զ��ӣ������Ҹ����ȥ���ϵĶ�����");
      	message_vision(CYN"\nֻ��$N������������ס$n�ֱ����ü��£��Ѿ���$n�еı������붾���ˡ�\n"NOR,oyf,me);
      	me->clear_condition("bing_poison");        
      	command("say ���������Ѿ����ˣ�Ϊ���ٰ���ƽ�������书����󡹦��Ҳ�����㡣");
      	tell_object(me, HIC "\n���˿�ʼ���㽲���󡹦�����Ź��򡣡���\n" NOR ); 
      	me->set("oyf_son", 1);
      	me->start_busy(5);
      	call_out("do_teach", 5, oyf, me);       
    
}

int add_exp(object me)
{
      	int i,lvl=1;
      	mapping skills;
      	string *sk;
      
      	skills = me->query_skills();
      	if (mapp(skills)) {
	  	sk = keys(skills);
	  	for (i=0;i<sizeof(sk);i++)
			skills[sk[i]]+=lvl;
	}
      	me->add("combat_exp",me->query("combat_exp")/(50-lvl)+lvl);
      	tell_object(me, "��Ĺ�������ˣ�\n"); 
      	return 1;
}	
	
void do_teach(object oyf, object me)
{
      	if(!me || environment(me) != environment(this_object())) return;
      
      	if(me->query("con") < 22) {
             	command("say �����Դ���Ϊ���ĵ����书����󡹦���������㲻�Ǹ�����Ĳ��ϡ�");
            	command("sigh");
             	command("say ֻ�а��������������е��书�ˡ�"); 
             	add_exp(me);
             	add_exp(me);
        }     
      	else{
             	tell_object(me, HIC "\n���˿�ʼ���㽲���󡹦�����Ź��򡣡���\n" NOR );
             	log_file("quest/hamagong", sprintf("%8s%-10s��Ϊŷ�������ӣ���ѧ��hmg��\n",
             		me->name(1),"("+me->query("id")+")"  ), me);
             	me->set("oyf/hamagong", 1);
                me->set_skill("hamagong", 50); 
                me->set_skill("hamabu",50);
          
             	add_exp(me);  
             	tell_object(me, "��ѧ���˸�󡹦��\n"); 
                tell_object(me, "��ѧ���˸�󡲽��\n");
             	command("chat �������������ҵ��ҵĹԶ�������");
        }         
      	call_out("do_back", 15, me);        
}

void oyf_cure1(object me, object oyf)
{
    
      	if(!me || !oyf || environment(me) != environment(this_object()) ) return;
      
      	command("hmm");
      	command("say �������������޻��������ҾͰ�����˶��ɡ�");
      	message_vision(CYN"\nֻ��$N������������ס$n�ֱ����ü��£��Ѿ���$n�еı������붾���ˡ�\n"NOR,oyf,me);
      	me->clear_condition("bing_poison");        
      	command("say ���������Ѿ����ˡ�");               
      	call_out("do_back", 5, me);     
}


void do_leave(object me)
{
      	object oyf = this_object();    
      
      	if(!me || !oyf || environment(me) != environment(this_object()) || !living(me)) return;
        
      	me->delete_temp("oyf"); 
  
      	message_vision("$N���۴��������ֻ����ü���˼����ͻȻ���ƺ����������ᣬ��ʱ��ɫ��䡣\n",oyf);
      	command("whisper " + me->query("id") + " �Һ���ǵ�һ���С�����ɽ���ĵط���������������");
      	if(me->query("oyf_son"))
             	command("whisper " + me->query("id") + " �����Ǹ����ڣ�Ȼ�������������������"); 
      	command("chat* pat " + me->query("id"));
      	message_vision("\n����$Nһ�����˳�ȥ����һ�����úô󣬴��õڶ������������������֮�⣬�����ʮ��������������ɣ������û�ˡ�\n\n",oyf);   
	if(!me->query("oyf_son")){
		me->set("quest/hama/fail", 4); 
		tell_object(me, "�㱻������50000�㾭��㣡\n");
        	me->add("combat_exp", 50000); 
        	me->add("max_neili", 200);
                tell_object(me, "����ڹ���Ϊ��������ٵ㣡\n");
    me->set("title",HIW"����ɽׯ"MAG"ŷ��������"NOR);
        	log_file("quest/hamagong", sprintf("%8s%-10s����ŷ���壬���õ�������\n", 
        		me->name(1),"("+me->query("id")+")" ), me);
        }
	
}
