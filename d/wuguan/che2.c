// che3.c ������
// By River@SJ
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIY"������"NOR);
        set("long", @LONG
�ɾ�����ĳ�����������λ�����ź�ɫ�Ľ��С���ǰ�ϳ�����������
�ظ����������е����������ڳ��ڣ�ȴ�����о��𵴡�͸���ĳ������ܹ���
�ʹ��������ľ�ɫ��
LONG
        );
        set("exits/out","/d/city/guangchang");

        set("no_fight",1);

        setup();
}

void init()
{
        object me=this_player();
        string arg,arg1;
        object place = me->query_temp("place");
        if (!place){
           tell_object(me,YEL"\n�����������Դ�˵������Ҫȥ���ﰡ���ҿ����ˣ��������㵽���ݳǰɡ�\n\n");
           return;
        }
        switch(place){
            case "Dali":      arg="/d/dali/dalics";        arg1 ="���ϴ����"; break;
            case "Gumu":      arg="/d/gumu/shengou";       arg1 ="����ɽ��Ĺ"; break;
            case "Wudang":    arg="/d/wudang/xuanyue";	arg1 ="�ӱ��䵱ɽ��"; break;
            case "Mingjiao":  arg="/d/mingjiao/shanjiao";  arg1 ="��������ɽ��"; break;
            case "Taohuadao": arg="/d/thd/guiyun/road4";   arg1 ="�����һ������¹���ׯǰ"; break;
            case "Shenlong":  arg="/d/sld/haitan";         arg1 ="��������̲"; break;
            case "Yangzhou":  arg="/d/city/guangchang";    arg1 ="�������ݳ�"; break;
            case "Murong":    arg="/d/mr/testmatou1";      arg1 ="���Ϲ���Ľ��"; break;
            case "Kunlun":    arg="/d/mingjiao/shanjiao";  arg1 ="����ɽ��"; break;
            case "Tiezhang":  arg="/d/tiezhang/shanjiao";  arg1 ="��������ɽ"; break;
            case "Shaolin":   arg="/d/shaolin/shijie1";    arg1 ="��ɽ��������ɽ"; break;
            case "Huashan":   arg="/d/huashan/path1";      arg1 ="������ɽɽ��"; break;
            case "Xingxiu":   arg="/d/xingxiu/xxh";        arg1 ="�������޺�"; break;
            case "Emei":      arg="/d/emei/qingshijie";    arg1 ="�Ĵ�����ɽ��"; break;
            case "Dalunsi":   arg="/d/xueshan/mingxiamen"; arg1 ="����ѩɽ������"; break;
            case "Quanzhen":  arg="/d/gumu/lyy";           arg1 ="����ɽȫ���"; break;
            default: break;
        }
        set("exits/out",arg);
        message_vision(YEL "\n����Ѵ󳵿���·�ԣ�����˵����"+arg1+"�Ѿ����ˣ����³���out���ɡ�\n\n"NOR,me);
}
