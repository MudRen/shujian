// wdroad8.c ����·
// By Spdierii@ty ����yttlg quest
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ɽ����");
	set("long", @LONG
�������䵱ɽ���£���������ɭɭ�����֡�������һ����ɽ, ���Ϸ���һ
��ͤ����ν͵�ø���������! û�б�����õ�Ъ�ŷ����ˡ�
LONG
	);
        set("outdoors","�䵱");

	set("exits", ([
		"east" : "/d/group/entry/wdroad7",
                "southeast" :"/d/wudang/chating",
                "west" : "/d/wudang/xuanyue",
	]));

	set("objects", ([
                "/d/wudang/npc/yetu" : 2 
	]));
        setup();
}
int valid_leave(object me, string dir)
 {
     if ( me->query_temp("quest/yttlg/story"))
             return notify_fail("�㻹���Ȱ��Ľ��հɣ���\n");
     return ::valid_leave(me, dir);
 }
void init()
{
  object me;
  me = this_player();
  if (me->query_temp("quest/yttlg/story"))
  {
     tell_object(me,HIW"��ͻȻ�����ж��ڳ���·����Ϣ,�������и߾���Ծ�����졣��\n"NOR); 
     tell_object(me,HIW"����վ������,�ƺ���������ʲô,ԭ�����ٰ��������ھֵ��ڳ���\n"NOR);       
     remove_call_out("story");
     call_out("story", 3, me);      
     write(CYN"\n�㲻�ɸе�ʮ�ֺ��棬��ͣ������������������\n"NOR);
}
}
void story(object me)
{
  if(!me) return;

   tell_object(me,YEL"\n���������䵱���ӡ������ⷬ���衱���ƺ����䵱����Щ������ȴ�������������˵ʲô���㲻�ɺ�������\n"NOR); 
   tell_object(me,YEL"\n������ǰȥ,˫�ֱ�ȭ,�ʵ�:��ֿ����ٰ��������ھ�ô?���ʼ�λ���մ�������ֶ�����ͷ�ɺá�\n"NOR);
   tell_object(me,YEL"\n����һ��������ǰ�����������±��Ƕ������������.....?\n"NOR); 
   tell_object(me,YEL"\n��΢΢һЦ,��:�䵱��ѧ֮��,��λ�����䵱�����ع��Ų��룿\n"NOR);
   tell_object(me,YEL"\n�������Ǽ�ʦ��ʮ�ٵ�֮�ڣ������������λҪ�£�������ɽȥ�ȱ��پ���Ρ�\n"NOR); 
   tell_object(me,YEL"\n�����΢ŭ��:����ʦ��Ҳ�������㰮���ѣ�������ʱ�����䵱ɽ���ˡ�\n"NOR);
   remove_call_out("story1");
   call_out("story1", 10, me);      
   write(CYN"\n����ö���������л�,�پ���֡�\n"NOR);


}
void story1(object me)
{
  if(!me) return;

   tell_object(me,YEL"\n������,���:��ô������ͷ������ʦ���ˣ�����һ������\n"NOR); 
   tell_object(me,YEL"\n������������½����������һ��֮�䣬�䵱�������˶�����ˡ�\n"NOR);
   tell_object(me,YEL"\n�㲻�ɡ�������һ��������һ�����ʵ�������������Ҳ������ô��\n"NOR); 
   tell_object(me,YEL"\n��������������������ô���ҿɲ�֪��һλ����������ֻ��������һ����ˣ���������Ҳ���ڡ�\n"NOR);
   tell_object(me,YEL"\n��ҡͷ�����Ǿ��Ʋ��ᣬ��ʦ�����ǽ���һֱ��ɽ���������̷�ʦ����û��ɽһ����\n"NOR); 
   tell_object(me,YEL"\n�����˵��:ʦ������ʦ�����������绹����ɽ����С����ɽ�Ⱥ����ض���ͷ�������ʦ�����ǡ�\n"NOR);
   remove_call_out("story2");
   call_out("story2", 10, me);      
   write(CYN"\n���ƺ�����������Щ���Ρ�\n"NOR);


}
void story2(object me)
{
  if(!me) return;
   tell_object(me,YEL"\n�����������λ����������һ�Ŵ���룬������������ë�ģ����δ����أ������������\n"NOR);
   tell_object(me,YEL"\n��һ�㣬������ʦ�ֵ�֮�У�����һ�˼������룬������ë��\n"NOR); 
   tell_object(me,YEL"\n����������⼸�仰��һ���������ĵ�ֱð������˵�����������Գ����䵱�����������䵱ɽ�������������������ǻƹڵ��ˣ�������Ȼ����\n"NOR);
   tell_object(me,YEL"\n���ڵ�����ʦ�����ǵ��ˣ��������յ�ȴ�����׼ҵ��ӡ��������Գ��ǡ��䵱������ô��\n"NOR); 
   tell_object(me,YEL"\n��������˰��Σ��ŵ��������˵����������ֻ�²������⣬���ǿ�׷����\n"NOR);
   remove_call_out("story3");
   call_out("story3", 10, me);      
   write(CYN"\n�㽥��������Щ���\n"NOR);

}
void story3(object me)
{
  if(!me) return;
   tell_object(me,YEL"\n�㲻��������˵��:�����˻�ð���������ֱ��ɵ�����ȥ�գ�\n"NOR);
   tell_object(me,YEL"\n������������ĵ�:���������أ�������������Ҫ�����������䵱ɽ�����������ˡ�\n"NOR); 
   tell_object(me,YEL"\n������������ĵ�:�����˼�ð�����������Ǹ���ȥ��ֻ�¡���ֻ������Ҫ�㡭������\n"NOR);
   tell_object(me,YEL"\n�����˲��������������˭������ʦ���������˽���˭ȥ��\n"NOR); 
   tell_object(me,YEL"\n�������������һ�潫�������������һ����������֮�������䵱ɽ֮��˵�ˣ���\n"NOR);
   remove_call_out("story4");
   call_out("story4", 10, me);      
   write(CYN"\n������������졣\n"NOR);

}
void story4(object me)
{
  if(!me) return;
   tell_object(me,YEL"\n�㲻���ʵ�:������֮������ô��������ò��Σ�\n"NOR);
   tell_object(me,YEL"\n���������Ҳ��֪��������˭�����˵ò���˵�������ܶ�����ֻʣ��һ�����ˡ�����ԼĪ��ʮ������͡�\n"NOR); 
   tell_object(me,YEL"\n���������˵�������˵�ģ����\n"NOR);
   tell_object(me,YEL"\n����һ�����е������⡭��������������簡��\n"NOR); 
   tell_object(me,YEL"\n�㼱�������������������ˣ���ͷ��˭���Ǻ����붼�������ǰ����\n"NOR);
   tell_object(me,YEL"\n���������ʻ��������ȴ��һ��Ҳ��������\n"NOR);
   tell_object(me,YEL"\n���������üͷ,���ʣ���������������ȥ����������ģ����\n"NOR); 
   tell_object(me,YEL"\n������Աߵ�ʷ��ͷ�ڳ���㣬����˵�ˡ�\n"NOR);
   tell_object(me,YEL"\n������ʦ���������ˣ��������˲�������֮�����У����ɵ��ļ���١�\n"NOR); 
   tell_object(me,YEL"\n�㼱����С���ȸ�һ����˵��΢һ��ȭ,������ȥ!\n"NOR);
   me->move("/d/wudang/shiqizhen");

}


