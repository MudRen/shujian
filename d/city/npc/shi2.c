// shi.c ʷ��ɽ
// Modified by snowman 21/05/2000

#include <ansi.h>
inherit NPC;
string ask_me();
int ask_job();
int do_proceed(object who, object ob);

void create()
{
       set_name("ʷ��ɽ", ({ "shi qingshan", "shi", "qingshan" }));
       set("title", "�����ؽ�");
       set("gender", "����");
       set("age", 33);
       set("str", 25);
       set("dex", 16);
       set("long", "ʷ��ɽ�������䵱ɽ���׼ҵ��ӣ��ָ�ؤ���е������ֻ�ǲ�֪Ϊ�γ����˳�͢����\n");
       set("combat_exp", 200000);
       set("shen_type", 1);
       set("attitude", "heroism");

       set_skill("unarmed", 100);
       set_skill("tiyunzong",100);
       set_skill("yinyun-ziqi",100);
       set_skill("force", 100);
       set_skill("sword", 100);
       set_skill("dodge", 100);
       set_skill("parry", 100);
       set_skill("stick", 100);
       set_skill("dagou-bang", 100);
       map_skill("parry", "dagou-bang");
       map_skill("stick", "dagou-bang");
       map_skill("dodge","tiyunzong");
       set_temp("apply/attack", 70);
       set_temp("apply/defense", 70);
       set_temp("apply/armor", 70);
       set_temp("apply/damage", 70);

        set("inquiry", ([
                "Ϊ��" : (: ask_me :),
                "��Ч��͢" : (: ask_me :),
//                "job" : (: ask_job :),
//                "����" : (: ask_job :),
       ]));
       
       set("max_qi", 1700);
       set("qi", 1700);
       set("neili", 2000); 
       set("max_neili", 2000);
       set("jiali", 30);

       setup();
       carry_object(BINGQI_D("langya-bang"))->wield();
       carry_object(ARMOR_D("armor"))->wear();
}

int accept_fight(object me)
{
       command("say �Ϸ��δ�ͽ����˶��ֹ����ˣ�����Ҳ����������");
       return 0;
}

void init()
{
       object ob;
       ::init();
       if (interactive(ob = this_player()) && living(this_object()) &&
               (int)ob->query_condition("killer")) {
               remove_call_out("kill_ob");
               call_out("kill_ob", 0, ob);
       }
}

int ask_job()
{
        object *all, *inv, ob, room, me=this_player();
	int i, j=0;

	if (me->query_temp("mark/Ѳ��", 1)){
		command("? "+me->query("id"));
		return 1;
	}

	if (me->query("PKS") > 50
        && me->query("combat_exp") / me->query("PKS") < 350000){
		command("hehe "+me->query("id"));
		command("say �������벻�������ɱ�������ĳ������Լ����������ˡ�");
		message_vision("$N���һ�������˰������Ұ���������ȥ��ͻȻ�����һ���ٱ���$n���廨����̧����ȥ��\n", this_object(), me);
		me->apply_condition("city_jail", 50);

		inv = all_inventory(me);
                for( i=0; i<sizeof(inv); i++ ) {
                	if( inv[i]->query_autoload() ) continue;
                	if( inv[i]->query("equipped") )
                		inv[i]->unequip();
                	destruct(inv[i]);
                }
		me->move("/d/city/dalao");
		message("vision","ֻ����ƹ����һ����һ��������Ķ��������˽�����\n", environment(me), me);
		return 1;
	}
	
	if(!( room = find_object("/d/taishan/fengchan")) )
        room = load_object("/d/taishan/fengchan");
        
        if (userp(me) && me->query("id") == room->query("winner") ) {
                command("say ����������ͨ���Ϸ�ɵ�������");
                return 1;
        }

	if (me->query("combat_exp") < 50000){
		command("say ������������Сë���������������Ȥ�Ϸ�");
		command("kick "+me->query("id"));
		me->move("/d/city/bingyingmen");
        	message("vision","ֻ����ƹ����һ����" +me->query("name") + "�ӱ�Ӫ����˳�����\n", environment(me), me);
		return 1;
	}

	all = users();

        for(i=0; i<sizeof(all); i++){
        	if( wiz_level(all[i]) ) continue;
         	if( all[i]->query_temp("mark/Ѳ��") )
                        j++;
                if (j > 6){
			command("shake");
			command("say �������ڲ�ȱ���֡�");
			return 1;
			break;
		}
	}

	say("ʷ��ɽ������Ц�����ã��Ϸ���ȱ���֣���������������������°ɣ�\n");
	me->set_temp("apply/short", ({ HIR" ����Ѳ��  "NOR+me->query("name")+"("+capitalize(me->query("id"))+")"}));
	ob = new("/d/city/obj/wenshu2");
	ob->move(me);
	me->set_temp("mark/Ѳ��", 1);
	write("ʷ��ɽ������ҳ�һ������ݸ��㡣\n");
	return 1;
}

int accept_object(object who, object ob)
{
	object room;
	
	if(!( room = find_object("/d/taishan/fengchan")) )
        room = load_object("/d/taishan/fengchan");

	if ( userp(ob) && ob->query("id") == room->query("winner") ){
		command("say �������ͨ�����ˣ�������������");
		command("say ���㻹���ȷ��˴��˵�����ͨ��ݰɣ�");
		return 0;
	}
	
        if (userp(ob) && ob->query("PKS") >= 50)
                return do_proceed(who, ob);
        return 0;
}

int do_proceed(object who, object ob)
{	
	object *inv, gold;
	int bonus, i;

	ob->clear_condition();
	ob->set("startroom", "/d/city/dalao");

	inv = all_inventory(ob);
	for( i=0; i<sizeof(inv); i++ ) {
                if( inv[i]->query_autoload() ) continue;
                if( inv[i]->query("equipped") )
                	inv[i]->unequip();
                destruct(inv[i]);
        }

	bonus = ob->query("combat_exp")/10;
	if (bonus > 3000) bonus = 3000;

	if(ob->query("PKS") > 99){
		ob->apply_condition("city_jail", 300);
	}

	else if(ob->query("PKS") > 74){
		bonus = bonus*2/3;
        	ob->apply_condition("city_jail", 200);
        }

	else if(ob->query("PKS") > 49){
		bonus = bonus*2/3;
		ob->apply_condition("city_jail", 100);
	}
	
	who->add("combat_exp", bonus);
	ob->add("comba_exp", -bonus);
	if(ob->query("city_jail") > 4)
		ob->apply_condition("city_jail", 400);
	
	ob->add("PKS", -1);
	ob->add("city_jail", 1);
	call_out("move_ob", 1, ob);
	
	message_vision("$N�Ը����Ҹ�$n�������ùǣ��Ͻ����Ρ�\n", this_object(), ob);

	command("thumb "+who->query("id"));
	gold=new("/clone/money/gold");
	gold->set_amount(10);
	gold->move(who);
	command("say �ɵúã���������ͽ���ȥЪ�Űɣ�");	
	write("ʷ��ɽ����һЩ�ƽ�\n");
	command("chat "+ob->query("title")+ob->query("name")+"�ڽ���"+ NATURE_D->game_time() +"�������ռࡣ");
	log_file("Jail", sprintf("%s(%s)��%s(%s)�ͽ� city jail on %s����EXP %d\n",
                  who->query("name"), who->query("id"), ob->query("name"), ob->query("id"), ctime(time()), bonus));
	return 1; 
}
void move_ob(object ob)
{
	if( !ob ) return;
	ob->move("/d/city/dalao");
	message("vision", "ֻ����ƹ����һ����һ��������ļһﱻ���˽�����\n", environment(ob), ob);
}

string ask_me()
{        
       	object me;
       	int gftimes;

       	me = this_player();
       	gftimes = (int)me->query("gf_job",1);
       
       	if (gftimes<1)
       		return "��λ"+RANK_D->query_respect(me)+"��û��Ϊ��͢����������̸�����أ���\n"; 
       	if (gftimes>=1 && gftimes<50)
       		return "��λ"+RANK_D->query_respect(me)+"Ŀǰ���Ͳ���������Ŭ���ɣ���\n"; 
       	if (gftimes>=50 && gftimes<100){
       		command("nod ");
       		command("say ���ѽ���Ĺ��ͱ����˱������飬ǰ�ձ�������������Ϊ�첶��");
       		me->set_temp("apply/short", ({HIY"��͢��Ա��Ʒ�첶 "NOR+me->name()+"("+me->query("id")+")"}));
       		return "�ұ������������Ϊ���ҳ�����Ϊ�����츣����\n"; 
       	}
       	if (gftimes>=100 && gftimes<200){
       		command("nod " + me->query("id"));
       		command("say ���ѽ���Ĺ��ͱ����˱������飬ǰ�ձ�������������Ϊ��ͷ��");
       		me->set_temp("apply/short", ({HIY"��͢��Ա��Ʒ��ͷ "NOR+me->name()+"("+me->query("id")+")"}));
       		return "�úøɣ��Ϸ��ǲ��������ģ�\n";
       	}
       	if (gftimes>=200 && gftimes<500){
       		command("pat " + me->query("id"));
       		command("say ��λ"+RANK_D->query_respect(me)+"�Ĺ������Դ��ߴ��С��ش�������Ϊ������");
       		me->set_temp("apply/short", ({HIY"��͢��Ա��Ʒ���� "NOR+me->name()+"("+me->query("id")+")"}));
       		return "��λ"+RANK_D->query_respect(me)+"�Ĺ��Ͳ�С���Ϸ��´ν�����һ��Ҫ��������������飡\n";
       	}
       	if (gftimes>=500 && gftimes<1000){
       		command("thumb " + me->query("id"));
       		me->set_temp("apply/short", ({HIY"��͢��Ա��Ʒ��˾ "NOR+me->name()+"("+me->query("id")+")"}));
       		return "��λ"+RANK_D->query_respect(me)+"�ĳɼ���С������Ҫ�ͽ������˴�Ļ��ȣ������ݹ��Ϸ��������飡\n";
       	}
       	if (gftimes>=500 && gftimes<1000){
       		command("haha " + me->query("id"));
       		command("say ��λ"+RANK_D->query_respect(me)+"���书���Ǿ�Ϊ������һ������Ŭ���ɣ�");
       		me->set_temp("apply/short", ({HIY"��͢��Ա��Ʒ�λ� "NOR+me->name()+"("+me->query("id")+")"}));
       		return "��˵������ϳ��н�������û����ȥ��鿴��\n";
       	}
       	if (gftimes>=1000 && gftimes<2000){
       		me->set_temp("apply/short", ({HIY"��͢��Ա��Ʒ�ν� "NOR+me->name()+"("+me->query("id")+")"}));
       		return "�Ϸ��Ѱ�����Ϊ�ν����Ժ�����»ָ�տɴ���\n";
       	}
       	if (gftimes>=2000 && gftimes<2500){
       		me->set_temp("apply/short", ({HIY"��͢��Ա����Ʒ���� "NOR+me->name()+"("+me->query("id")+")"}));
       		return "��˵����������Ҫ����ǰȥ���ǣ����Ժ�ǰ;Զ�󰡣�\n";
       	}
       	if (gftimes>=2500 && gftimes<3000){
       		me->set_temp("apply/short", ({HIY"��͢������Ʒ�ܱ� "NOR+me->name()+"("+me->query("id")+")"}));
       		return "��˵����������Ҫ����ǰȥ���ǣ����Ժ�ǰ;Զ�󰡣�\n";
       	}
       	if (gftimes>=3000 && gftimes<3500){
       		me->set_temp("apply/short", ({HIY"��͢�س���һƷ�ᶽ "NOR+me->name()+"("+me->query("id")+")"}));
       		return "��˵����������Ҫ����ǰȥ���ǣ����Ժ�ǰ;Զ�󰡣�\n";
       	}
        if (gftimes>=3500 && gftimes<4500){
        	me->set_temp("apply/short", ({HIY"��͢�س���һƷ�󽫾� "NOR+me->name()+"("+me->query("id")+")"}));
       		return "��˵����������Ҫ����ǰȥ���ǣ����Ժ�ǰ;Զ�󰡣�\n";
        }
       	if (gftimes>4500){
       		me->set_temp("apply/short", ({HIY"��͢�ղ�� "NOR+me->name()+"("+me->query("id")+")"})); //wiz get it now
       		return "���ᣬ����ѹ����ı��Ϸ򻹴�\n";
       	}
}

void die()
{
        object killer;
        if(objectp(killer = query_temp("last_damage_from")) ){
                killer->apply_condition("killer", killer->query_condition("killer")+100);
                command("say "+killer->name()+"�㾹��ıɱ��͢���٣����˰�������");
                }
        ::die();
}    
