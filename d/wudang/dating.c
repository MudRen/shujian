// dating.c ����
// By Spiderii@ty ����yttlg quest
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�䵱����");
	set("long", @LONG
�����䵱ɽ�������Ĵ���,��Ϊ�������䵱����ʦ������ľ�ʮ�ٳ�֮��,����
���ܱ��˲��õĺ������ա����м�һ����������,͸¶��ϲ�졣��ϧ��ʱ�˿�
ȴ������������֮�⡣ֻ��������һ�˱�����˫�֣���ͣ����������ȥ��
LONG
	);

        setup();
}
void init()
{
  object me;
  me = this_player();
  if (me->query_temp("quest/yttlg/story2"))
  {
     remove_call_out("bihua");
     call_out("bihua", 3, me);      
     write(CYN"\n������������������񣬲������أ�����ʦ����\n"NOR);
}
}
void bihua(object me)
{
  if(!me) return;

   tell_object(me,HIC"\nֻ������������һ�ᣬ����ͥ������Ȼ������֣��ڿ���һ��һ����д��������\n"NOR); 
   tell_object(me,HIC"\n������������ʣ���ʫд�֣�������˾�ռ��ߣ�Ҳ����Ϊ�졣\n"NOR);
   tell_object(me,HIC"\n��˳������ָ�ıʻ���ȥ��ԭ��д���ǡ�ɥ�ҡ����֣���д�˼��飬������д��ݱ�������֡�\n"NOR); 
   tell_object(me,HIC"\n������һ������ʦ�����ڿ��١�ɥ����������\n"NOR);
   tell_object(me,HIC"\n��ʱ����������ʦ������ָ�ٿ����顰��֮���ף�ɥ��֮������Ĺ����ݱ����׷Ω��������ʮ�˸��֡�\n"NOR); 
   tell_object(me,HIC"\nһ��һ��֮�г����˷�������֮������ʱ����������֮������д�⡰ɥ������ʱ�����顣\n"NOR);
   remove_call_out("bihua1");
   call_out("bihua1", 10, me);      
}
void bihua1(object me)
{
  if(!me) return;

   tell_object(me,HIC"\n����֮�Ƕ���ʱ�ˣ���ʱ��ԭ�嵴���������壬��л���ţ����±ܿܣ���ɥ��֮�࣬\n"NOR); 
   tell_object(me,HIC"\n���˷�Ĺ���ⶾ�֣�����˵������ǻ��ʹ�������������飬���������ڡ�ɥ�������С�\n"NOR);
   tell_object(me,HIC"\n��ʱ������ʦ�ִ���Ī��Ĵ�����������ˡ�ɥ�ҡ����֡���ݱ�������֡���׷Ω���������֡�\n"NOR); 
   tell_object(me,HIC"\n������д�˼��飬����̾�˿�����������ͥ���������Σ������ָ����д����������һ��д���������Բ�ͬ��\n"NOR);
   tell_object(me,HIC"\n��˳��ʦ������ָ���ƿ�ȥ,������һ���Ǹ����䡱�֣��ڶ���д�˸����֡��֣�һ·д���������Ƕ�ʮ���֡�\n"NOR); 
   tell_object(me,HIC"\n�����ʲ��ᵽ�����Ǽ��仰�����������𡢱����������������£�Ī�Ҳ��ӡ����첻����˭�����棿��\n"NOR);
   remove_call_out("bihua2");
   call_out("bihua2", 10, me);      
   write(CYN"\n�㰵������,ʦ��������ĥ���ʮ�ĸ��������������⣬��������ʦ��������ˡ�\n"NOR);


}
void bihua2(object me)
{
  if(!me) return;

   tell_object(me,HIC"\nֻ��������д��һ������һ�飬�Ƕ�ʮ�ĸ��ַ�����ȥ����д���ʻ�Խ��Խ��������ȴԽ��Խ����\n"NOR); 
   tell_object(me,HIC"\n�������ݺῪ�أ�����ʩչȭ��һ�㡣\n"NOR);
   tell_object(me,HIC"\n������ۿ��������־���ϲ��ʦ����д�Ķ�ʮ�ĸ��ֺ���һ�𣬷������׼��������书��\n"NOR); 
   tell_object(me,HIC"\nÿһ�ְ������У���������仯���������ֺ͡��桱�ֱʻ����࣬�������ֺ͡��¡��ֱʻ����١�\n"NOR);
   tell_object(me,HIC"\n���ʻ���Ĳ����䷱���ʻ��ٵĲ�����ª������Ҳ���أ��Ƴ��֮��������Ҳ�վ��������֮�ѡ�\n"NOR); 
   tell_object(me,HIC"\n���캨�����ۻ�ս������ݴ����Ʈ����ѩ�裬���ش��绢�ף����󲽡���\n"NOR);
   remove_call_out("bihua3");
   call_out("bihua3", 10, me);      
   write(CYN"\n����Ŀѣ���֮�ʣ��漴Ǳ�ļ��䡣��\n"NOR);


}
void bihua3(object me)
{
  if(!me) return;

   tell_object(me,HIC"\n���ʮ�ĸ����й��������������֣��������족�֡�\n"NOR); 
   tell_object(me,HIC"\n������д����ͬ���ⲻͬ�����ƶ����ƣ��仯֮��������һ����\n"NOR);
   tell_object(me,HIC"\n�������ٵ�֮��,��˴��,��֮�����������ʮ�ĸ�����Ϊһ���书��\n"NOR); 
   tell_object(me,HIC"\n��һ��ȭ����������һ����һ��ķ�����չ���������������ʱ����\n"NOR);
   tell_object(me,HIC"\n������ӿ���죬����Хһ��������ֱ���������������ǽ���â��\n"NOR); 
   tell_object(me,HIC"\n��ʸӦ��������Ͼ�����粻���ɣ���һֱ���ǡ��桱�ֵ����һ�ʡ���\n"NOR);
   tell_object(me,HIC"\n����������ң����˵������ͽ������һ·�鷨��Σ�����\n"NOR); 
   tell_object(me,HIC"\n�����һ�����벻���Լ���������ʦ���䲻��ͷ��ȴ��֪���ˡ���\n"NOR);
   tell_object(me,HIC"\n�㵱���ߵ����ڣ�˵���������ӵÿ�ʦ�����գ����Ǵ��۸�����ȥ�д�ʦ�����ǳ���һ��հ������ô����\n"NOR);
   tell_object(me,HIC"\n������ҡͷ�������������Ѿ���ֻ����Ҳд���������ĺ����ˡ�Զ�š���Ϫ���ǲ����鷨�����ǿ��ˣ�Ҳ���򲻶ࡣ��\n"NOR);
   tell_object(me,HIC"\n����������һ�ӣ�˵��:��Ҳ��ȥ�ɡ�˵�ս������á�\n"NOR);
   me->set_temp("quest/yttlg/ask",1);
   me->delete_temp("quest/yttlg/story2",1);   
   me->move("/d/wudang/sanqing");

}
