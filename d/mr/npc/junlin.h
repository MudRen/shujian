string ask_junlin()
{
        object me=this_player();
        if (me->query("family/family_name") != "����Ľ��")
                return RANK_D->query_respect(me)+"�뱾��������������֪�˻��Ӻ�̸��";

if( me->query("family/master_name") != "Ľ�ݲ�" )
return RANK_D->query_respect(me)+"������Ե����֪�˻��Ӻ�̸��";
if(me->query("quest/junlin/pass"))
return RANK_D->query_respect(me)+"�����Ѿ����վ������µ�������ô��";
if ( !present("shixi biao", this_player()))
return RANK_D->query_respect(me)+"�ѵ���֪�������µ������ڴ������ϵ���У�";

if(me->query_temp("quest/junlin/ask"))
return RANK_D->query_respect(me)+"�ѵ���֪�������µ������ڴ������ϵ����!";
if(me->query("quest/junlin/fail") > 3)
return RANK_D->query_respect(me)+"�����������������Ե!";

//�书ѧϰ֮����Ҫ���һ��
 if(me->query("quest/junlin"+"time") && time()-me->query("quest/junlin"+"time")<86400)
        {
          command("shake "+me->query("id"));
command("say ��һ������ô��Σ�Ҳ�������ţ�QUEST�������ô��Ҫ����");
return "ЪЪ��";
  }

// me->set("quest/junlin"+"time",time());
me->set_temp("quest/junlin/ask",1);
return "�����������Ľ�ݰ���Ľ�ݴ���Ľ������Ľ�ݵ£�����Ӣ�ۺ��ܣ��������¡�";

}

int accept_object(object me, object obj)
{
if(me->query("quest/junlin"+"time") && time()-me->query("quest/junlin"+"time")<86400)
        {
command("say ��һ������ô��Σ�Ҳ�������ţ�QUEST�������ô��Ҫ����");
return 0;
}
if(me->query("quest/junlin/pass"))
{
command("say �㲻���Ѿ����վ������µ�������ô��");
return 0;
}
if(me->query("quest/junlin/fail") > 3)
{
command("say ������������������Ե��");
return 0;
}

if(obj->query("owner")!=me->query("id"))
{
command("say �����Ū�����ⶫ����");
return 0;
}
if(obj->query("id") == "shixi biao" && me->query_temp("quest/junlin/ask") &&
me->query("family/family_name")=="����Ľ��")
{
command("say ����������Ҵ������ϵ�����֪����ϵ���г��˼����Ҵ�����������֮�⣬������һ���ش����ܣ�");
me->set("quest/junlin"+"time",time());
me->start_busy(999);  
call_out("destructing", 1, obj);
 remove_call_out("thinking");
           call_out("thinking",3, me );
return 1;
}
 else return 0;
             }

void destructing(object obj)
{
	destruct(obj);
}
int thinking(object me)
{
if(!me) return 0;
tell_object(me,HIG"\nĽ�ݲ�ͻ�ذεض���ʮָ������ָ�缤���ȥ�����϶��£��������磬�������߷緶��\n"NOR);
command("smile ");
command("say ��ɿ������ˣ�");
tell_object(me,HIY"\n�㿪ʼ����Ļ���Ľ�ݲ�����ʽ...\n"NOR);
remove_call_out("thinking1");
call_out("thinking1",5, me );
}

int thinking1(object me)
{
  int i;
  if(!me) return 0;
	
  if(me->query_temp("junlin")<(3+random(3)))
    { me->add_temp("junlin",1);
          if(random(2)) tell_object(me,HIG"\n����������Ÿղ�Ľ�ݲ���һ��һʽ...\n"NOR);
             else tell_object(me,HIY"\nͻȻ�䣬���ƺ�ץ����ʲô...\n"NOR);
	  tell_room(environment(me),HIC""+me->query("name")+"�ƺ���˼����ʲô��üͷ���塣\n"NOR, ({}));
	  remove_call_out("thinking1");
	  call_out("thinking1",3+random(3), me);
	}

else
   {  me->delete_temp("junlin");
     
if( random(me->query("kar"))> 28  && random(15)==1 && me->query("buyvip"))

     {
        tell_object(me,HIM"\n���Ȼ�������飬�̶���Цһ�����ȵ����ڶ�ָ���������̺᡹��\n"NOR);
    message_vision(HIC"\n$N�����ʹ�þ��������ƺ���Щ�˽��ˡ�\n"NOR,me); 
   tell_object(me,HIM"\n����������һָ���յ��������һ�С���ָ��ɽ�ơ�����ɽ�续���쳾���Σ�ָ���絶��\n"NOR);  
message_vision(HIC"\nĽ�ݲ�������Ц���Ҵ�����˸�������\n"NOR,me); 
     me->set("quest/junlin/pass", 1);
  
       log_file("quest/junlin", sprintf("%s(%s) ʧ��%d�γɹ��⿪�������¡���Դ��%d�����飺%d��",     
          me->name(1),
          me->query("id"), 
          me->query("quest/junlin/fail"),
          me->query("kar"),
          me->query("combat_exp")) );
me->start_busy(1);
     }

    else
    {
       tell_object(me,HIG"\n���˼��ã�����Ҫ�졣\n"NOR);
       message_vision(HIC"\n$Nҡ��ҡͷ�������̾�˿�����\n"NOR,me); 
      tell_object(me,HBBLU"\n�ܿ�ϧ���㱾�γ��Ծ������½���ʧ�ܣ�\n"NOR);
   tell_object(me,HBBLU"��Ŀǰ�ľ�����" + me->query("combat_exp") + "������ʱ�����齣"+ NATURE_D->game_time() + "�����¼��\n"NOR);
      tell_object(me,HBBLU"�㽫�ڼ��24Сʱ������һ�λ��ᣡ��\n\n"NOR);
       me->add("quest/junlin/fail,1");
      
       me->start_busy(1);
  
    }

  }

}
