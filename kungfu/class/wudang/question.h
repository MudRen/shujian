string ask_wdjiuyang()
{
        object me=this_player();
        if (me->query("family/family_name") != "�䵱��")
                return RANK_D->query_respect(me)+"�뱾��������������֪�˻��Ӻ�̸��";

/*
        if (me->query("age",1) > 16)
        	command("knock "+me->query("id"));
		return "����������ʱ������������ˡ�";
*/	

        if (me->query("shen") <0 )
		return "����ȥ�ĸɻ����ˣ�";
if (me->query("quest/wdjiuyang/pass"))
	       return "�㻹ûѧ����";

if (me->query("combat_exp")<5000000 || me->query("int")<33 || me->query("kar")<28 )
	       return "�㻹��ץ��ʱ��ȥ����ȥ�ɡ�";


if (me->query_temp("wdjiuyang_ask"))
 return "û��û�˵��ʸ�ʲô��";
if (me->query("quest/wdjiuyang/fail") > 3 && !me->query("buyvip"))
return "��������ʣ������ѧ�Ͳ�Ҫ������";

//�书ѧϰ֮����Ҫ���һ��
 if(me->query("quest/wdjiuyang"+"time") && time()-me->query("quest/wdjiuyang"+"time")<86400)
        {
          command("shake "+me->query("id"));
command("say ��һ������ô��Σ�Ҳ�������ţ�QUEST�������ô��Ҫ����");
return "ЪЪ��";
  }
me->set_temp("wdjiuyang_ask",1);

me->set("quest/wdjiuyang"+"time",time());
	return "������������̣��ٻ������ǰ�����\n"
        "�������㼸�����⣬��ֻ��ش�(answer)���𰸼��ɡ�\n"
        "׼��������(answer yes/no)��\n";

     // �Ի�ҩ������û��arg,�ش�y or n����ν��������ʵ������ʾ��Ҹ�answer �ˡ�

}
int questions(object me)
{
	string answer;
if (me->query_temp("wdjiuyang/question")>10) 
{
  command("say ���������Ҿ͸�����һЩ���°ɡ�");
// me->set("quest/wdjiuyang"+"time",time());
    me->set_temp("wdjiuyang1",1);
me->delete_temp("wdjiuyang/question");
remove_call_out("meet");
	call_out("meet", 3);
return 1;
}                


command("say ��ش�");

switch (random(11)) {
		case 0:
			command("say ����������ĳ�Ů����ʲô��");
			answer = "��ܽ";
			break;
		case 1:
			command("say �����������СŮ����ʲô��");
			answer = "����";
			break;
		case 2:
			command("say �ҵ���ҵ��ʦ����ʲô��");
			answer = "��Զ";
			break;
		case 3:
			command("say ������ʱ�����ֽ���ʲô��");
			answer = "�ž���";
			break;

               case 4:
			command("say ����С��������ɽɽ��֮�����еĴʣ���������ʲô��");
			answer = "������";
			break;
               case 5:
			command("say ��ɫ��ʦ�����е�ְ����ʲô��");
			answer = "�޺�������";
			break;
              case 6:
			command("say ���Ǿ�Զʦ������ܷ���");
			answer = "���ܲ���";
			break;
               case 7:
			command("say ��ɫ��ʦ��������С���ʫ��Ӻζ�����");
			answer = "�޺����Ͻ����޺����������";
			break;

               case 8:
			command("say ������Դ���Ҫ��������С����������������׹ŷ��ں϶�����");
			answer = "��������";
			break;
               case 9:
			command("say ������ʱ�������·����Ǻ��ˣ�");
			answer = "����";
			break;
               case 10:
			command("say ��������ʲô��ʽ����������ʥ���У�");
			answer = "ƫ������";
			break;








}
	this_object()->set("answer",answer);
	return 1;
}

int meet(object me)
{
me = this_player();
tell_object(me,CYN"\n�����Ỻ��˵�����������һ�����......��\n"NOR);   
tell_object(me,CYN"\n������������Ĺ��£����������ԣ��·������侳һ�㡣\n"NOR);  
remove_call_out("meet1");
        call_out("meet1", 4, me);
        return 1;
}
// ������д���⣬δ�����������by hongba 2012 1.21 �賿1:32

int do_answer(string arg)
{
	object me = this_player();
	
	if (!arg)
		return notify_fail("��Ҫ�ش�ʲô��\n");
 if( (int)me->is_busy() || me->is_fighting()) 
return notify_fail("����æ���أ��𼱣�������\n");  // Ϊ��ֹflood answer����busy����������ҲӦ�ü���
if (me->query_temp("wdjiuyang1"))
return notify_fail("���ˣ������ٻش��ˡ�\n");
if(!me->query_temp("wdjiuyang_ask"))
return notify_fail("���ƺ�������BUGĲ��������CUT��һ��EXP��\n");

	if (arg != this_object()->query("answer")) {
		
		command("shake " + me->query("id")); 
 me->start_busy(random(3));
	}
	else {
		command("say �ţ�û����ܺá�");
me->start_busy(random(3));
		

		me->add_temp("wdjiuyang/question",1); 
	}

me->start_busy(random(3));
	call_out("questions", 1, me);
	return 1;
}
int meet1(object me)
{
me = this_player();
tell_object(me,WHT"\n����֮�У���·�������һ������......\n"NOR);  
me->move("/kungfu/class/wudang/shijie");
return 1;
}


int ask_wdjiuyang1()
{
        object me=this_player();
object ob = this_object();

if(!me->query_temp("wdjiuyang4"))
{
command("say ���������ʲô?");
return 1;
}
if (me->query("quest/wdjiuyang/fail") > 3 && !me->query("buyvip"))
{
command("say ��������ʣ��ҿ������ͱ��������ˡ�");
return 1;
}

me->set_temp("quest/wdjiuyang/ask",1);
 me->delete_temp("wdjiuyang4");
command("pat "+me->query("id"));
 message_vision(HIC"\n\n$n�����Զʦ��������Щ���ӣ���ʵ��Ҳδ����ȫ����ֻ�ܸ�������ô�࣬ʣ���˿�����컯�ա�\n"NOR,me,ob); 
remove_call_out("thinkingjy");
call_out("thinkingjy",5, me, ob);
tell_object(me,WHT"��ƴ���ػ���������Ļ�����ʼ����˼����.........\n"NOR);
    me->start_busy(2);
          return 1;
}

int thinkingjy(object me, object ob)
{
        int p;
        int i,j=0;
                object* ppl;

        if(!me) return 0;

        ppl= users();

  if(me->query_temp("wdjiuyang_thinking")<(3+random(3)))
        {
                me->add_temp("wdjiuyang_thinking",1);
    if(random(2)) tell_object(me,HIG"\n��Ŭ���ػ���ղ�������Ļ�,ֻ����ͷ����װ...\n"NOR);
    else tell_object(me,HIY"\nͻȻ�䣬���ƺ�ץ����ʲô����Ŭ���ػ���ղ�������Ļ������ƺ���ᵽ�����еı仯����...\n"NOR);
          tell_room(environment(me),HIC""+me->query("name")+"�ƺ���˼����ʲô��һ����ü��չ�����ӡ�\n"NOR, ({}));
remove_call_out("thinkingjy");
call_out("thinkingjy",3+random(3), me, ob);
        }
        else
        {
    me->delete_temp("wdjiuyang_thinking");

        p=random(200);
i = sizeof(ppl);
while(i--){
 if( userp(ppl[i])&& !wizardp(ppl[i])&&!ppl[i]->query("no_pk")&& ppl[i]->query("quest/wdjiuyang/pass"))
        j++;

}

//j<=3
        if(p ==7 &&random( me->query("kar"))>28 && me->query("kar")<31 && j<=3 )
    {
       tell_object(me,HIG"\n���ʱ���½��ղ���ᵽ�Ķ������ˣ�������ϥ���£�һ��һ���������䡣\n"NOR);
       tell_object(me,HIG"\n�㵱��֮���������������ݼ��֡�Ҳ��֪���˶���ʱ�򣬲Ž���Щ����Ļ����ü����ء�\n");
       tell_object(me,HIG"\n��ֻ���ﲨ��������ɵ����Ӿ�Э���������ƣ�ȫ������ƮƮ�ģ��������Ƽ���һ�㡣\n");
       message_vision(HIC"\n$N������������Ц������˵������ԭ����ˣ�ԭ����ˡ���\n"NOR,me); 
tell_object(me,HIR"�������������ָ��,�����������䵱��������һЩҪ�죬ʣ�µľ�Ҫ�Լ������ˡ�\n"NOR);
       me->set("quest/wdjiuyang/pass",1);
       me->delete_temp("quest/wdjiuyang/ask");
       me->set_skill("wudang-jiuyang",1);
        log_file("quest/wdjiuyang", sprintf(HIR"%s(%s) �ɹ��⿪�䵱��������Դ��%d�����飺%d��\n"NOR, me->name(1),me->query("id"), me->query("kar"),me->query("combat_exp")) );
    }
    else
    {
       tell_object(me,HIG"\n���Ժ����ƺ�ץס��ʲô��������Ȼ���Ǻ����ס�\n"NOR);
       message_vision(HIC"\n$Nҡ��ҡͷ�������������Ǻ����ѵġ���˵�գ������̾�˿�����\n"NOR,me); 
       command("poor "+me->query("id"));
       me->add("quest/wdjiuyang/fail",1);
               log_file("quest/wdjiuyang", sprintf(HIR"%s(%s) ���䵱����ʧ�ܡ���Դ��%d�����飺%d��\n"NOR, me->name(1),me->query("id"), me->query("kar"),me->query("combat_exp")) );
    }
  }
  return 1;
}


