// ask.c
// LinuX@SJ 2004/03/09 

#include <ansi.h>
inherit F_CLEAN_UP;

string query_inquiry(object me,object ob);

string *msg_dunno = ({
	CYN"$nҡҡͷ��˵����û��˵����\n"NOR,
	CYN"$n�����۾�����$N����Ȼ��֪��$P��˵ʲô��\n"NOR,
	CYN"$n�����ʼ磬�ܱ�Ǹ��˵���޿ɷ�档\n"NOR,
	CYN"$n˵�����š������ҿɲ��������������ʱ��˰ɡ�\n"NOR,
	CYN"$n����һ�����˵�����Բ������ʵ�����ʵ��û��ӡ��\n"NOR,
	CYN"$nҡҡͷ��˵������û�������ġ�\n"NOR,
	CYN"$n�����ʼ磬�ܱ�Ǹ��˵���Ҷ���̸������Ȥ��\n"NOR,
	CYN"$n���ͷ��ĵ���$Nһ�ۣ�˵����û������æ����\n"NOR,
	CYN"$n����$Nһ�ۣ�˵�����Բ����ֽ���æ�Լ�����ȥ�ˡ�\n"NOR,
	CYN"$nЦ��������$N��˵����������ʲô��\n"NOR,
	CYN"$n�ϴ�Ը��Ŀ���$Nһ�ۣ���ת����ȥ�ˡ�\n"NOR,
	CYN"$n��ݺݵص���$Nһ�ۣ�˵�����������أ������ң���\n"NOR,
	CYN"$n������һ�ۣ��Գ�һ�������ε����ӣ�ҡ��ҡͷ��\n"NOR,
	CYN"$n�����ʼ磬�ܱ�Ǹ��˵���޿ɷ�档\n"NOR,
	CYN"$n˵�����Ҿ���$n�����ѵ���֪���𣿡�\n"NOR,
	CYN"$n˵����.............................��\n"NOR,
	CYN"$n˵��������Ҫ�н��ƣ������߻���ħ����\n"NOR,
	CYN"$N��û���ü�ͬ$n��̸��$n��ת����ȥ�ˡ�\n"NOR,
	CYN"$n˵�����Ǻǣ����ô���������������������ã���\n"NOR,
	CYN"$n˵�������佲����ٽݾ������ֻ�Ǹ���ʦ��ѧ���ǲ����кý���ġ�\n"NOR
});

string *msg_party = ({
	CYN"$n����һ����˵��������$T�㶼û��˵�����ҿ����ǲ�����˰ա�\n"NOR,
	CYN"$nͦ�ش���������Ҫ����ѧ�䣬���ռ�������$Tû��\n"NOR,
	CYN"$n��ݺݵض�$N˵���������ӷ����㣬�������Ǹ�ʲô�ġ�\n"NOR,
	CYN"$nС��˵���������������$T��\n"NOR,
	CYN"$n�����˵������������˭��֪������$T�����ţ�\n"NOR,
	CYN"$n�����ؿ���$Nһ�ۣ������������������$T�������ʲô��\n"NOR
});

string *msg_foreign = ({
        CYN"$n˵��������˵������ɣ��Ҳ��ᣬ����ô�����������\n"NOR,
        CYN"$n����Ц������˵ʲô���\n"NOR,
        CYN"$n˵�����Ű����ȹ����³���㿴����Ҳ�ܼ�װ��˵�������\n"NOR
});

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string dest, msg, topic, att;
	object ob;
	int iyes = 0;
	//int m;
	
	if (me->is_busy())
		return notify_fail("����Ъ������˵���ɡ�\n");

	if (!arg || sscanf(arg, "%s about %s", dest, topic) != 2)
		return notify_fail("��Ҫ��˭ʲô�£�\n");

	if (!objectp(ob = present(dest, environment(me))))
		return notify_fail("����û������ˡ�\n");

	if (ob == me) return notify_fail("���Լ���\n");
	if (!ob->is_character()) {
		message_vision("$N����$n���������\n", me, ob);
		return 1;
	}
	if (ob->query("mute"))
		message_vision("���Ǻܿ�ϧ��$N����˵����\n", ob);

	if (!ob->query("can_speak")) {
		message_vision("$N��$n�����йء�" + HIG +topic + NOR + "������Ϣ������$p��Ȼ�������˻���\n", me, ob);
		return 1;
	}

	if ( iyes = !INQUIRY_D->parse_inquiry(me, ob, topic))
		message_vision("$N��$n�����йء�" + HIG +topic + NOR + "������Ϣ��\n", me, ob);

	if (userp(ob)) return 1;
	if (!living(ob)) {
		message_vision("���Ǻ���Ȼ�ģ�$n���ڵ�״��û�а취��$N�κδ𸲡�\n", me, ob);
		return 1;
	}
	
	

	dest = base_name(environment(ob));

	if ((msg = ob->query("startroom"))
	&& msg != dest
	&& (msg = ob->query("lastroom"))
	&& (msg == dest || msg->is_character())
	&& ob->query("inquiry/" + topic, 1))
		message_vision(CYN "$N˵����"+RANK_D->query_self(ob)+"�ǳ�����ɽ��ˮ�ģ����ش����⡣\n" NOR, ob);
	else if (msg = ob->query("inquiry/" + topic)) {
		if (stringp(msg)) ob->force_me("say " + msg);
	}
	/*else if ( topic=="all" ){	// add by LinuX@SJ
		 query_inquiry(me,ob);
	} */
	else if (topic[0] < 128  && iyes) {
                message_vision(msg_foreign[random(sizeof(msg_foreign))], me, ob);
	}
	else {
		if (ob->query("mute"))
			message_vision("���Ǻܿ�ϧ��$N����˵����\n", ob);
		else switch(topic) {
			case "name":
				att = ob->query("attitude");		
				switch (att)
				{
				case "aggressive":
				case "killer":
					message_vision(YEL"$N��$n����һ�ɣ�"+RANK_D->query_self_rude(ob)
						+"�������ǿ����������𣿣��ҿ�����"+RANK_D->query_rude(me)
						+"�ǻ����ˣ�\n"NOR, ob, me);
					break;	
				case "heroism":
					message_vision(CYN"$N��$n����һЦ��"+ob->query("name")+"����"
						+RANK_D->query_self_rude(ob)+"��\n"NOR, ob, me);
					break;
				case "peaceful":
				case "friendly":
					message_vision(CYN"$N��$n����һҾ����λ"+RANK_D->query_respect(me)
						+"����Ὺ��Ц����ô��ͻȻ����"+RANK_D->query_self(ob)
						+"�����֣�\n"NOR, ob, me);
					EMOTE_D->do_emote(ob, "sigh", ob->query("id"), 0);
					break;	
				default:
					message_vision(CYN"$N��$n����һҾ����λ"+RANK_D->query_respect(me)
						+"����Ὺ��Ц����ô��ͻȻ����"+RANK_D->query_self(ob)
						+"�����֣�\n"NOR, ob, me);
					EMOTE_D->do_emote(ob, "sigh", ob->query("id"), 0);
					break;	
				}		
				break;
			case "here":
				message_vision(CYN "$n��$N˵����������" + environment(ob)->query("short") + CYN "���������" + RANK_D->query_self(ob) + "Ҳ��̫�����\n" NOR, me, ob);
				break;
			case "rumors":
				EMOTE_D->do_emote(ob, "dunno");
				break;
			case "news":
			case "����":
			case "����":
                                EMOTE_D->do_emote(ob, "nod");
                                msg = "/cmds/usr/news.c"->read_last_news();
                                //message_vision( CYN "$N������˵�ͷ˵�����������˵��һ��������Ŷ���������ĸ�����ɡ�\n" NOR, ob);
                                ob->force_me("whisper " + me->query("id") +" "+msg);
                                break;
                        case "bbb":
                        case "yuj":
                        case "linux":
                        	EMOTE_D->do_emote(ob, "fear");
                        	message_vision(CYN "$N��$n˵��������������ǰ����ô���µ����ֺò��á���\n" NOR, ob,me);
				break;
			/*case "�ζ�����":
				if ((int)ob->query_skill("force",1) < 60 ) 
					message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
				else if(!me->query("family") || me->query("family/master_id") != ob->query("id")) 
					message_vision(CYN "$N˵�����������ܴ�ͨ�ζ��������ڹ���������Ϊ������н�չ����\n" NOR, ob);
				else if((int)me->query_skill("force",1) < 100 ) 
					message_vision(CYN "$N��$n˵���������ڹ���Ϊ���㣬���ǿ�д�ͨ�ζ�������ֻ�����˾�������\n" NOR, ob,me);
				else if(me->query("quest/rendu_2m")) 
					message_vision(CYN "$N����$n���ۣ�����ص��������ζ��������Ѵ�ͨ�˰ɡ���\n" NOR, ob,me);
				else if((int)me->query_skill("force",1) > 120 ) 
					message_vision(CYN "$N��$n˵����������ڹ���Ϊ����Ѿ����ƺ��ζ����������д�ͨ�ˡ���\n" NOR, ob,me);
				else if((int)ob->query_skill("force",1) < 140 ) 
					message_vision(CYN "$N�����Գ�һ˿�ѹ��������������������ڵ��ڹ���Ϊ��ֻ�»��޷���ͨ����ζ���������\n" NOR, ob);
				else
				{
					int m;
					me->set("quest/rendu_2m",1);
					message_vision(HIW "$N����$n���ۣ����˵�ͷ��������$nͷ���أ���ǰ������һ�ơ�\n" NOR, ob,me);  
					m = me->query("con")+ random(me->query("con"))+random((int)me->query_skill("force",1)/10);
					me->set_skill("force",(int)me->query_skill("force",1)+random(5));
					me->add("eff_jingli",m);
					me->add("max_jingli",m);
					me->add("max_neili",m + random(10));
					write(HIG"\n��ֻ��ȫ����ϢͻȻһ�ͣ�������ͨ�ޱȣ��ƺ������������ȥ�����ܼ��ļ�����Ѩ��\n"
						"��΢һ�������е���������ǰ����ǿ����࣬����ҲΪ֮һ��\n"NOR);
					me->start_busy(8);
				}
				break;*/
			default:
				if (topic == ob->query("name") || ob->id(topic))
					message_vision(CYN "$N˵�����Ǿ���" + RANK_D->query_self_rude(ob) + CYN "ѽ��\n" NOR, ob);
				else if (topic == me->query("name") || me->id(topic) || topic =="��ͷ" || topic =="С��")
					message_vision(CYN "$N˵�����Ǿ���" + RANK_D->query_rude(me) + CYN "��ѽ��\n" NOR, ob);
				else if (topic == me->query("family/family_name"))
					message_vision(CYN "$N�����" + RANK_D->query_rude(me) + CYN "�������"+topic+"��Ҫ�����\n" NOR, ob);
				else if (topic == ob->query("family/family_name")){
					msg = msg_party[random(sizeof(msg_party))];
					msg = replace_string(msg, "$T", topic);
					message_vision(msg, me, ob);
				}
				else
					message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
		}
	}
	me->add_busy(1);
	return 1;
}
//��npc���϶�ȡinquiry
/*string query_inquiry(object me,object ob)
{
	int i, j;
	mapping inq;
	string str="", msg, *indexs;
	j = 0;
	
	if(mapp(inq=ob->query("inquiry")))
	{
		indexs = sort_array(keys(inq),1);
		i = sizeof(indexs);
		if (i < 5)
		{
			while(i--){
	        	msg = indexs[i]; 
	        	if (i == 0)
	                	str = str + sprintf("%s",msg);
	                else	        	    
	                	str = str + sprintf("%s��",msg);
			}	
			ob->force_me("whisper " + me->query("id") + " ��������Ҵ����й�" + HIG +
			str + NOR + "�ȵ����飬�ҿ���һһ�����㡣");	
		}
		else
		{
		        while(i--){
		        	msg = indexs[i];
		        	//if (random(3)) continue;      
		                str = str + sprintf("%-10s",msg);
				j++;
				if (j % 8 == 0) str = str + "\n";
		        }
		        ob->force_me("whisper " + me->query("id") + " ��������Ҵ����й�\n" + HIG +
			str + NOR + "\n��Щ���飬�ҿ���һһ�����㡣");
		}

		return "";
	}
	ob->force_me("say ʵ���ǶԲ���,��ʲôҲ��֪��ѽ!");
	return "";
}*/
int help(object me)
{
	write( @HELP
ָ���ʽ: ask <someone> about <something>

���ָ���ڽ���ʱ����Ҫ, ͨ��������ɴ�һָ�����
��ý�һ������Ѷ��
HELP
	);
	return 1;
}
