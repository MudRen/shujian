// ���㾭��ĺ�����������������飬
// ������Ǳ��֮ǰ���á�

int cal_exp(int exp, object me)
{
    switch(me->query("family/family_name")) {
// �ȼ� C
        case "������":
        case "������":
        case "��ɽ��":
        case "�һ���":
        case "������":
        case "�䵱��":
              return (int)(exp*2/3);
          break;
// �ȼ� B �ľ��鱶���� 1���Ͳ��г��ˡ�
// �ȼ� A
        case "����":
        case "���ư�":
        case "������":
              return (int)(exp*4/3);
          break;
// �ȼ� A+
        case "������":
        case "������":
              return (int)(exp*3/2);
          break;
    }
    return exp;
}

